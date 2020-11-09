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


int GetDistinctRealRootCount(double a, double b, double c) {
	return 0;
}


void TestTwoRoots() {
	AssertEqual(GetDistinctRealRootCount(2, 5, -3), 2, "equation has 2 roots");
	AssertEqual(GetDistinctRealRootCount(0.1, 22, 0), 2, "equation has 2 roots");
	AssertEqual(GetDistinctRealRootCount(-20, -10, 2), 2, "equation has 2 roots");
	AssertEqual(GetDistinctRealRootCount(10.3, 4.8, -2.3), 2, "equation has 2 roots");
}

void TestLinearEquation() {
	AssertEqual(GetDistinctRealRootCount(0, 2, 3), 1, "equation has 1 root");
	AssertEqual(GetDistinctRealRootCount(0, -0.5, -10), 1, "equation has 1 root");
	AssertEqual(GetDistinctRealRootCount(0, 10, 0), 1, "equation has 1 root");
}

void TestNoRoots() {
	AssertEqual(GetDistinctRealRootCount(10, 4.8, 10), 0, "equation has no roots");
	AssertEqual(GetDistinctRealRootCount(-8.7, -14.3, -100), 0, "equation has no roots");
	AssertEqual(GetDistinctRealRootCount(1000, 22, 2123), 0, "equation has no roots");
}

void TestConstant() {
	AssertEqual(GetDistinctRealRootCount(0, 0, 10), 0, "equation has no roots");
	AssertEqual(GetDistinctRealRootCount(0, 0, -2), 0, "equation has no roots");
	AssertEqual(GetDistinctRealRootCount(0, 0, -10.12), 0, "equation has no roots");
}

void TestOneRoot() {
	AssertEqual(GetDistinctRealRootCount(1, -4, 4), 1, "equation has 1 root");
	AssertEqual(GetDistinctRealRootCount(-0.64, -4, -6.25), 1, "equation has 1 root");
	AssertEqual(GetDistinctRealRootCount(441, 298.2, 50.41), 1, "equation has 1 root");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestConstant, "TestConstant");
  runner.RunTest(TestLinearEquation, "TestLinearEquation");
  runner.RunTest(TestNoRoots, "TestNoRoots");
  runner.RunTest(TestOneRoot, "TestOneRoot");
  runner.RunTest(TestTwoRoots, "TestTwoRoots");
  return 0;
}
