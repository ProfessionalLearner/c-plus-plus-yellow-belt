#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
	auto it = find_if(begin(numbers), end(numbers), [](int i) {
		return i < 0;
	});

	for(auto iter = it; iter != begin(numbers); ) {
		cout << *(--iter) << " ";
	}
}


