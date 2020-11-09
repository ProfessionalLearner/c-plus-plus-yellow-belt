#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	if((range_end - range_begin) < 2) {
		return;
	} else {
		vector<typename RandomIt::value_type> elements(range_begin, range_end);

		auto iter = elements.begin() + (range_end - range_begin) / 2;
		MergeSort(elements.begin(), iter);
		MergeSort(iter, elements.end());
		merge(elements.begin(), iter, iter, elements.end(), range_begin);
	}
}

