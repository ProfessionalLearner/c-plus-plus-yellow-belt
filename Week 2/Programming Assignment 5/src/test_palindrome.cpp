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


bool IsPalindrom(const string& str) {

}

void TestEmpty() {
	string s = "";
	Assert(IsPalindrom(s), "empty");
}

void TestOneChar() {
	string s = "a";
	Assert(IsPalindrom(s), "one char");
}

void TestPalindroms() {
	string s1 = "madam";
	string s2 = "racecar";
	string s3 = "baab";
	string s4 = "ba ab";
	string s5 = " ABBA ";
	string s6 = "a b C b a";
	string s7 = "abCba";
	Assert(IsPalindrom(s1), "s1");
	Assert(IsPalindrom(s2), "s2");
	Assert(IsPalindrom(s3), "s3");
	Assert(IsPalindrom(s4), "s4");
	Assert(IsPalindrom(s5), "s5");
	Assert(IsPalindrom(s6), "s6");
	Assert(IsPalindrom(s7), "s7");
}

void TestNonPalindroms() {
	string s1 = "horn";
	string s2 = "banana";
	string s3 = "beets";
	string s4 = "ha wk";
	string s5 = "was it car";
	string s6 = "CbaabD";
	string s7 = "ABBA  ";
	string s8 = "  ABBA";
	string s9 = "was it a car or a cat i saw";
	string s10 = "abCDba";
	string s11 = "Cabba";
	string s12 = "abbaD";
	Assert(!IsPalindrom(s1), "s1");
	Assert(!IsPalindrom(s2), "s2");
	Assert(!IsPalindrom(s3), "s3");
	Assert(!IsPalindrom(s4), "s4");
	Assert(!IsPalindrom(s5), "s5");
	Assert(!IsPalindrom(s6), "s6");
	Assert(!IsPalindrom(s7), "s7");
	Assert(!IsPalindrom(s8), "s8");
	Assert(!IsPalindrom(s9), "s9");
	Assert(!IsPalindrom(s10), "s10");
	Assert(!IsPalindrom(s11), "s11");
	Assert(!IsPalindrom(s12), "s12");
}

int main() {
  TestRunner runner;
  runner.RunTest(TestEmpty, "TestEmpty");
  runner.RunTest(TestOneChar, "TestOneChar");
  runner.RunTest(TestPalindroms, "TestPalindroms");
  runner.RunTest(TestNonPalindroms, "TestNonPalindroms");
  return 0;
}
