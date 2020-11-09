#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	int range = range_end - range_begin;
	if(range < 2) {
		return;
	} else {
		vector<typename RandomIt::value_type> elements(range_begin, range_end);
		auto iter1 = elements.begin() + range / 3;
		auto iter2 = elements.begin() + range * 2 / 3;

		MergeSort(elements.begin(), iter1);
		MergeSort(iter1, iter2);
		MergeSort(iter2, elements.end());

		vector<typename RandomIt::value_type> inter_elements;

		merge(elements.begin(), iter1, iter1, iter2, back_inserter(inter_elements));
		merge(inter_elements.begin(), inter_elements.end(), iter2, elements.end(), range_begin);
	}
}
