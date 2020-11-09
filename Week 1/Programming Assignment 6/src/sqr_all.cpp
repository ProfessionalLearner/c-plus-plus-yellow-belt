#include <vector>
#include <map>
#include <fstream>
#include <set>
#include <cmath>
#include <algorithm>
#include <string>
#include <utility>
#include <iostream>
using namespace std;

template <typename T>
T Sqr(T value);

template <typename T>
vector<T> Sqr(const vector<T>& v);

template <typename K, typename V>
pair<K, V> Sqr(const pair<K, V>& p);

template <typename K, typename V>
map<K,V> Sqr(const map<K, V>& m);

template <typename T>
T Sqr(T value) {
	return value * value;
}

template <typename T>
vector<T> Sqr(const vector<T>& v) {
	vector<T> result;
	for(const T& x : v) {
		result.push_back(Sqr(x));
	}
	return result;
}

template <typename K, typename V>
pair<K, V> Sqr(const pair<K, V>& p) {
	return {Sqr(p.first), Sqr(p.second)};
}

template <typename K, typename V>
map<K,V> Sqr(const map<K, V>& m) {
	map<K, V> result;
	for(const auto& item : m) {
		result[item.first] = Sqr(item.second);
	}
	return result;
}


