#include "database.h"

void Database::Add(const Date& date, const string& event) {
	if(!entries_set[date].count(event)) {
		entries_set[date].insert(event);
		entries[date].push_back(event);
	}
}

void Database::Print(ostream& out) const {
	for(const auto& entry : entries) {
		for(const auto& event : entry.second) {
			out << entry.first << " " << event << endl;
		}
	}
}

string Database::Last(const Date& date) const {
	auto itr = entries.upper_bound(date);
	if(itr != entries.begin()) {
		--itr;
		return itr->first.toString() + " " + itr->second.back();
	}
	return "No entries";
}



ostream& operator << (ostream& stream, const Entry& entry) {
	return stream << entry.date << " " << entry.event;
}



