#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

class Person {
public:
  // Вы можете вставлять сюда различные реализации класса,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
  void ChangeFirstName(int year, const string& first_name) {
  }
  void ChangeLastName(int year, const string& last_name) {
  }
  string GetFullName(int year) {
  }
};

void TestOneName() {
	Person person;

	person.ChangeFirstName(1943, "John");
	person.ChangeLastName(1946, "Doe");

	AssertEqual(person.GetFullName(1942), "Incognito");
	AssertEqual(person.GetFullName(1944), "John with unknown last name");
	AssertEqual(person.GetFullName(1947), "John Doe");
}

void TestMultipleChanges() {
	Person person;

	person.ChangeLastName(1943, "Doe");
	person.ChangeFirstName(1946, "John");

	AssertEqual(person.GetFullName(1942), "Incognito");
	AssertEqual(person.GetFullName(1944), "Doe with unknown first name");
	AssertEqual(person.GetFullName(1947), "John Doe");

	person.ChangeFirstName(1948, "Bill");
	AssertEqual(person.GetFullName(1947), "John Doe");
	AssertEqual(person.GetFullName(1948), "Bill Doe");
	AssertEqual(person.GetFullName(1949), "Bill Doe");

	person.ChangeLastName(1947, "Wayne");
	AssertEqual(person.GetFullName(1946), "John Doe");
	AssertEqual(person.GetFullName(1947), "John Wayne");
	AssertEqual(person.GetFullName(1948), "Bill Wayne");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestOneName, "TestOneName");
  runner.RunTest(TestMultipleChanges, "TestMultipleChanges");
  return 0;
}
