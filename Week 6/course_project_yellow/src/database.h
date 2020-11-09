#pragma once
#include "date.h"
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;

struct Entry {
	Date date;
	string event;
};

class Database {
public:
	void Add(const Date& date, const string& event);

	void Print(ostream& out) const;

	template<typename Predicate>
	int RemoveIf(const Predicate& predicate) {
		int result = 0;
		vector<Date> dates_to_delete;

		for(auto& entry : entries) {
			vector<string> unremoved_events;
			for(auto& event : entry.second) {
				if(predicate(entry.first, event)) {
					entries_set[entry.first].erase(event);
					result++;
				} else {
					unremoved_events.push_back(event);
				}
			}

			if(unremoved_events.size() == 0) {
				dates_to_delete.push_back(entry.first);
			} else {
				entry.second = unremoved_events;
			}
		}

		for(const auto& date : dates_to_delete) {
			entries_set.erase(date);
			entries.erase(date);
		}

		return result;
	}

	template<typename Predicate>
	vector<Entry> FindIf(const Predicate& predicate) const {
		vector<Entry> result;
		for(const auto& entry : entries) {
			for(const auto& event : entry.second) {
				if(predicate(entry.first, event)) {
					Entry e{entry.first, event};
					result.push_back(e);
				}
			}
		}
		return result;
	}

	string Last(const Date& date) const;
private:
	map<Date, vector<string>> entries;
	map<Date, set<string>> entries_set;
};

ostream& operator << (ostream& stream, const Entry& entry);
