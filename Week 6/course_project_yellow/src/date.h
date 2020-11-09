#pragma once
#include <iostream>

using namespace std;

class Date {
public:
	Date(const int& new_year, const int& new_month, const int& new_day);
	int GetYear() const;
	int GetMonth() const;
	int GetDay() const;
	string toString() const;
private:
	int year;
	int month;
	int day;
};

Date ParseDate(istream& is);

ostream& operator << (ostream& out, const Date& date);

bool operator < (const Date& lhs, const Date& rhs);
bool operator <= (const Date& lhs, const Date& rhs);
bool operator >= (const Date& lhs, const Date& rhs);
bool operator == (const Date& lhs, const Date& rhs);
bool operator > (const Date& lhs, const Date& rhs);
bool operator != (const Date& lhs, const Date& rhs);
