/*문자열 집합*/ 

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<string, bool> s;
	string val;
	for (int i = 0; i < n; i++) {
		cin >> val;
		s[val] = 1;
	}
	int cnt = 0;
	string findwords;
	for (int i = 0; i < m; i++) {
		cin >> findwords;
		if (s[findwords]) {
			cnt++;
		}
	}
	cout << cnt;
}