#include "date.h"
#include <iomanip>
#include <sstream>
#include <iostream>
#include <vector>

Date::Date(const int& new_year, const int& new_month, const int& new_day) {
	  year = new_year;
	  if(new_month > 12 || new_month < 1)  {
		  throw logic_error("Month value is invalid: " + to_string(new_month));
	  }

	  month = new_month;

	  if(new_day > 31 || new_day < 1) {
		  throw logic_error("Day value is invalid: " + to_string(new_day));
	  }

	  day = new_day;
}

int Date::GetYear() const {
	return year;
}

int Date::GetMonth() const {
	return month;
}

int Date::GetDay() const {
	return day;
}

string Date::toString() const {
	stringstream ss;
	ss << *this;
	return ss.str();
}

Date ParseDate(istream& is) {
	int year, month, day;
	is >> year;
	is.ignore();
	is >> month;
	is.ignore();
	is >> day;
	return Date(year, month, day);
}


ostream& operator << (ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.GetYear()
			<< "-" << setw(2) << setfill('0') << date.GetMonth()
			<< "-" << setw(2) << setfill('0') << date.GetDay();
	return stream;
}

bool operator < (const Date& lhs, const Date& rhs) {
	vector<int> lhs_vector = {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()};
	vector<int> rhs_vector = {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
	return lhs_vector < rhs_vector;
}

bool operator <= (const Date& lhs, const Date& rhs) {
	vector<int> lhs_vector = {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()};
	vector<int> rhs_vector = {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
	return lhs_vector <= rhs_vector;
}

bool operator >= (const Date& lhs, const Date& rhs) {
	vector<int> lhs_vector = {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()};
	vector<int> rhs_vector = {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
	return lhs_vector >= rhs_vector;
}

bool operator == (const Date& lhs, const Date& rhs) {
	vector<int> lhs_vector = {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()};
	vector<int> rhs_vector = {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
	return lhs_vector == rhs_vector;
}

bool operator > (const Date& lhs, const Date& rhs) {
	vector<int> lhs_vector = {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()};
	vector<int> rhs_vector = {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
	return lhs_vector > rhs_vector;
}

bool operator != (const Date& lhs, const Date& rhs) {
	vector<int> lhs_vector = {lhs.GetYear(), lhs.GetMonth(), lhs.GetDay()};
	vector<int> rhs_vector = {rhs.GetYear(), rhs.GetMonth(), rhs.GetDay()};
	return lhs_vector != rhs_vector;
}
