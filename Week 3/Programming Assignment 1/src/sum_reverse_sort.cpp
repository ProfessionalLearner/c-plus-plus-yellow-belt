#include <iostream>
#include <algorithm>
#include "sum_reverse_sort.h"
using namespace std;

int Sum(int x, int y) {
	int sum = x + y;
	return sum;
}
string Reverse(string s) {
	reverse(s.begin(), s.end());
	return s;
}

void Sort(vector<int>& nums) {
	sort(begin(nums), end(nums));
}
