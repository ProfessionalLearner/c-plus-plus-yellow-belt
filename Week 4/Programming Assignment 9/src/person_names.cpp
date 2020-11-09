#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;


// если имя неизвестно, возвращает пустую строку
string FindNameByYear(const map<int, string>& names, int year) {
  string name;
  auto iter = names.upper_bound(year);
  if(iter != names.begin()) {
	  auto something = prev(iter);
	  name = something->second;
  }
  return name;
}

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
	    first_names[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
	    last_names[year] = last_name;
  }
  string GetFullName(int year) {
	  string first_name = FindNameByYear(first_names, year);
	  string last_name = FindNameByYear(last_names, year);

	    // если и имя, и фамилия неизвестны
	    if (first_name.empty() && last_name.empty()) {
	      return "Incognito";

	    // если неизвестно только имя
	    } else if (first_name.empty()) {
	      return last_name + " with unknown first name";

	    // если неизвестна только фамилия
	    } else if (last_name.empty()) {
	      return first_name + " with unknown last name";

	    // если известны и имя, и фамилия
	    } else {
	      return first_name + " " + last_name;
	    }

  }

private:
  map<int, string> first_names;
  map<int, string> last_names;
};

