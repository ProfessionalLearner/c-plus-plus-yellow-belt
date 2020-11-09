#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> result(n);
	for(int i = 0; i < n; i++) {
		result[i] = i + 1;
	}

	reverse(begin(result), end(result));

	do {
		for(int i = 0; i < n; i++) {
			cout << result[i] << " ";
		}

		cout << endl;
	} while(prev_permutation(begin(result), end(result)));


	return 0;
}
