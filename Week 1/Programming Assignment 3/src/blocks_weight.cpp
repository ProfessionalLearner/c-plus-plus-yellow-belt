#include <vector>
#include <iostream>
using namespace std;


int main() {
	int n, r;
	cin >> n >> r;

	uint64_t sum = 0;
	for(int i = 0; i < n; i++) {
		uint16_t w, h, d;
		cin >> w >> h >> d;

		sum += static_cast<uint64_t>(w) * h * d;
	}

	sum *= r;
	cout << sum << endl;
	return 0;
}
