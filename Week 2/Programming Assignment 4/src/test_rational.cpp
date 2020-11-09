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

class Rational {
public:


  Rational() {

  }
  Rational(int numerator, int denominator) {
  }

  int Numerator() const {
  }

  int Denominator() const {
  }
};

void TestNegativeBoth() {
	Rational r1 = Rational(-1244, -36888);
	AssertEqual(r1.Numerator(), 311);
	AssertEqual(r1.Denominator(), 9222);
	Rational r2 = Rational(-39, -333);
	AssertEqual(r2.Numerator(), 13);
	AssertEqual(r2.Denominator(), 111);
}

void TestPositiveBoth() {
	Rational r1 = Rational(1320, 12000);
	AssertEqual(r1.Numerator(), 11);
	AssertEqual(r1.Denominator(), 100);
	Rational r2 = Rational(36, 6);
	AssertEqual(r2.Numerator(), 6);
	AssertEqual(r2.Denominator(), 1);
}

void TestZeroNum() {
	Rational r1 = Rational(0, 12);
	AssertEqual(r1.Numerator(), 0);
	AssertEqual(r1.Denominator(), 1);
	Rational r2 = Rational(0, -213);
	AssertEqual(r2.Numerator(), 0);
	AssertEqual(r2.Denominator(), 1);
}

void TestDifferentSigns() {
	Rational r1 = Rational(-3, 9);
	AssertEqual(r1.Numerator(), -1);
	AssertEqual(r1.Denominator(), 3);
	Rational r2 = Rational(16, -40);
	AssertEqual(r2.Numerator(), -2);
	AssertEqual(r2.Denominator(),5);
}

void TestDefault() {
	Rational r = Rational();
	AssertEqual(r.Numerator(), 0);
	AssertEqual(r.Denominator(), 1);
}

void TestUndivided() {
	Rational r1 = Rational(7, 9);
	AssertEqual(r1.Numerator(), 7);
	AssertEqual(r1.Denominator(),9);
	Rational r2 = Rational(-7, -9);
	AssertEqual(r2.Numerator(), 7);
	AssertEqual(r2.Denominator(), 9);
	Rational r3 = Rational(7, -9);
	AssertEqual(r3.Numerator(), -7);
	AssertEqual(r3.Denominator(), 9);
}

void TestDivided() {
	Rational r1 = Rational(281235, 281235);
	AssertEqual(r1.Numerator(), 1);
	AssertEqual(r1.Denominator(), 1);
	Rational r2 = Rational(-13, -13);
	AssertEqual(r2.Numerator(), 1);
	AssertEqual(r2.Denominator(), 1);
	Rational r3 = Rational(15, -15);
	AssertEqual(r3.Numerator(), -1);
	AssertEqual(r3.Denominator(), 1);
}
int main() {
  TestRunner runner;
  runner.RunTest(TestNegativeBoth, "TestNegativeBoth");
  runner.RunTest(TestPositiveBoth, "TestPositiveBoth");
  runner.RunTest(TestDifferentSigns, "TestDifferentSigns");
  runner.RunTest(TestDefault, "TestDefault");
  runner.RunTest(TestDivided, "TestDivided");
  runner.RunTest(TestUndivided, "TestUndivided");
  runner.RunTest(TestZeroNum, "TestZeroNum");
  return 0;
}
