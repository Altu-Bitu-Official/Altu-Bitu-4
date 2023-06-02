#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	
	int n, m, ans;
	cin >> n >> m;

	set<string> s; // 문자열 집합 s
	string str;

	while(n--) {
		cin >> str;
		s.insert(str);
	}
	
	while(m--) {
		cin >> str;
		if(s.find(str) != s.end()) { // 집합에서 찾았으면
			ans++;                   // 개수 증가
		}
	}

	cout << ans;

	return 0;
}