#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

enum class Gender {
  FEMALE,
  MALE
};

struct Person {
  int age;  // возраст
  Gender gender;  // пол
  bool is_employed;  // имеет ли работу
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
  if (range_begin == range_end) {
    return 0;
  }
  vector<typename InputIt::value_type> range_copy(range_begin, range_end);
  auto middle = begin(range_copy) + range_copy.size() / 2;
  nth_element(
      begin(range_copy), middle, end(range_copy),
      [](const Person& lhs, const Person& rhs) {
        return lhs.age < rhs.age;
      }
  );
  return middle->age;
}

void PrintStats(vector<Person> persons) {
	int median = ComputeMedianAge(begin(persons), end(persons));
	auto iter_f = partition(begin(persons), end(persons), [](Person p) {
		return p.gender == Gender::FEMALE;
	});
	int median_f = ComputeMedianAge(begin(persons), iter_f);
	int median_m = ComputeMedianAge(iter_f, end(persons));
	auto iter_f_u = partition(begin(persons), iter_f, [](Person p) {
		return !p.is_employed;
	});
	auto iter_m_u = partition(iter_f, end(persons), [](Person p) {
		return !p.is_employed;
	});
	int median_f_e = ComputeMedianAge(iter_f_u, iter_f);
	int median_f_u = ComputeMedianAge(begin(persons), iter_f_u);
	int median_m_e = ComputeMedianAge(iter_m_u, end(persons));
	int median_m_u = ComputeMedianAge(iter_f, iter_m_u);
	cout << "Median age = " << median << endl;
	cout << "Median age for females = " << median_f << endl;
	cout << "Median age for males = " << median_m << endl;
	cout << "Median age for employed females = " << median_f_e << endl;
	cout << "Median age for unemployed females = "<< median_f_u << endl;
	cout << "Median age for employed males = "<< median_m_e << endl;
	cout << "Median age for unemployed males =  "<< median_m_u << endl;
}


