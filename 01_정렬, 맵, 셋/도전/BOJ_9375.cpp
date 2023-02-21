#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int clothes(const int& n) {
	map<string, vector<string>> clothes_map;
	set<string> type_set;
	string name, type;
	
	for (int i = 0; i < n; i++) {
		cin >> name >> type;
		type_set.insert(type);
		clothes_map[type].push_back(name);
	}

	vector<string> type_vector;
	type_vector.assign(type_set.begin(), type_set.end());

	int result = 1;
	for (int i = 0; i < type_vector.size(); i++) {
		result *= (clothes_map[type_vector[i]].size() + 1);
	}

	return result - 1;
}

int main() {
	int t, n;
	
	//입력
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		//연산 & 출력
		cout << clothes(n) << "\n";
	}

	return 0;
}