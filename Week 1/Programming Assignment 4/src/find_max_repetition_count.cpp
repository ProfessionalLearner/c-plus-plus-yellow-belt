#include <map>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};




bool operator < (const Region& lhs, const Region& rhs) {
	return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
			tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(vector<Region>& regions) {
	map<Region, int> regions_count;
	for(Region& region : regions) {
		++regions_count[region];
	}

	int max_count = 0;
	for(auto& item : regions_count) {
		if(item.second > max_count) {
			max_count = item.second;
		}
	}

	return max_count;
}


