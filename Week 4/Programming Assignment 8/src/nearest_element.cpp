#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <set>
using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers, int border) {
	const auto first_lower = numbers.lower_bound(border);

	if(first_lower == numbers.begin()) {
		return first_lower;
	}

	const auto previous = prev(first_lower);
	if(first_lower == numbers.end()) {
		return previous;
	}

	return (border - *previous <= *first_lower - border) ? previous : first_lower;
}

