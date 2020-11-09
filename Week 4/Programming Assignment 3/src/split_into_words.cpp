#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
using namespace std;


vector<string> SplitIntoWords(const string& s) {
	vector<string> result;
	auto str_beg = begin(s);
	const auto str_end = end(s);
	while(true) {
		auto it = find(str_beg, str_end, ' ');

		result.push_back(string(str_beg, it));
		if(it == str_end) {
			break;
		} else {
			str_beg = it + 1;
		}
	}

	return result;
}
