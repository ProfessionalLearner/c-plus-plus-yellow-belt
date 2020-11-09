#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <iostream>
using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	vector<T> result;
	auto it = find_if(begin(elements), end(elements), [&border](T e) {
		return e > border;
	});

	for(auto iter = it; iter != end(elements);) {
		result.push_back(*(iter++));
	}

	return result;
}

