#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, cnt = 0;
	vector<string> s;
	string input;

	//입력
	cin >> n >> m;
	s.assign(n, {});
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	//연산
	sort(s.begin(), s.end());
	for (int i = 0; i < m; i++) {
		cin >> input;
		if (binary_search(s.begin(), s.end(), input)) cnt++;
	}
	//출력
	cout << cnt << '\n';

	return 0;
}