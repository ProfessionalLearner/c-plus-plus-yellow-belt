#include <iostream>
#include <sstream>
#include "phone_number.h"
using namespace std;

PhoneNumber::PhoneNumber(const string& international_number) {
	istringstream ss(international_number);
	char c = ss.get();

	getline(ss, country_code_, '-');
	getline(ss, city_code_, '-');
	getline(ss, local_number_);

	if(c != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty()) {
		throw invalid_argument("");
	}
}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}

string PhoneNumber::GetCityCode() const {
	return city_code_;
}

string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	return ("+" +  country_code_ + "-" + city_code_ + "-" + local_number_);
}
