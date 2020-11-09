#include <vector>
#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	int64_t sum = 0;
	for(int& item : v) {
		cin >> item;
		sum += item;
	}

	int avg = sum / n;

	vector<int> result;

	for(int i = 0; i < n; i++) {
		if(v[i] > avg) {
			result.push_back(i);
		}
	}

	cout << result.size() << endl;
	for(int j : result) {
		cout << j << " ";
	}
	cout << endl;

	return 0;
}
