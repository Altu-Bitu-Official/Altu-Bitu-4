#include <iostream>
#include <set>
#include <vector>
using namespace std;

// n개에는 중복이 없지만 m개에는 중복 있을 수 있음
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	int cnt = 0;
	string s1, s2;
	set <string> S;
	
	cin >> n >> m;
	// n개의 문자열 입력 (집합 S에 포함된 문자열)
	for (int i = 0; i < n; i++) {
		cin >> s1;
		S.insert(s1);
	}
	// 검사해야 하는 m개의 문자열 입력
	for (int i = 0; i < m; i++) {
		cin >> s2;
		// 
		if (S.count(s2) != 0) cnt++;
	}
	cout << cnt;
	return 0;
}
