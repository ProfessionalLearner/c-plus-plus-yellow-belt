#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;



template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix) {
	string str(1, prefix);
	return equal_range(range_begin, range_end, str, [](string lhs, string rhs) {
		return lhs[0] < rhs[0];
	});

}






