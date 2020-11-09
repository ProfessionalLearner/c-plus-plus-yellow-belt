#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix) {
	return equal_range(range_begin, range_end, prefix, [&prefix](string lhs, string rhs) {
		return lhs.compare(0, prefix.length(), rhs.substr(0, prefix.length())) < 0;
	});

}
