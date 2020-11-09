#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <map>
using namespace std;


struct Operation {
	char type = 0;
	int num = 0;
};


bool hasGreaterPriority(const char& operation1, const char& operation2) {
	return (operation1 == '+' || operation1 == '-') && (operation2 == '*' || operation2 == '/');
}


int main() {
	int x;
	cin >> x;
	int n;
	cin >> n;

	vector<Operation> operations(n);
	for(int i = 0; i < n; i++) {
		cin >> operations[i].type;
		cin >> operations[i].num;
	}

	deque<string> result;
	result.push_back(to_string(x));

	for(int j = 0; j < n; j++) {
		if(j != 0) {
			if(hasGreaterPriority(operations[j - 1].type, operations[j].type)){
				result.push_front("(");
				result.push_back(")");
			}
		}

		result.push_back(" ");
		result.push_back(string(1, operations[j].type));
		result.push_back(" ");
		result.push_back(to_string(operations[j].num));
	}

	for(auto it = result.begin(); it != result.end(); ++it) {
		cout << *it;
	}

	cout << endl;

	return 0;
}
