#include <vector>
#include <map>
#include <fstream>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>
#include <stdexcept>
#include <iostream>
#include <exception>
using namespace std;



template <typename K, typename V>
V& GetRefStrict(map<K, V>& m, const K& key) {
	if(m.count(key)) {
		throw runtime_error("");
	}
	return m.at(key);
}

