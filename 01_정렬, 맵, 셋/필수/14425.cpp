#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, ans = 0;
	string input;
	set<string> s;

	//입력
	cin >> n >> m;

	while (n--) {
		cin >> input;
		s.insert(input);
	}

	//연산
	while (m--) {
		cin >> input;
		if (s.find(input) != s.end()) { // 같은게 있으면 ans +1
			ans++;
		}
	}

	//출력
	cout << ans;

	return 0;
}