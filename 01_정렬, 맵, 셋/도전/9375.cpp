#include <iostream>
#include <map>

using namespace std;

/*
* map을 이용하여 종류 별로 옷의 개수 파악
* 알몸인 경우 제외 (전체 - 1)
*/

int main()
{
	int t, n;
	string outfit, outfit_type;
	// 입력
	cin >> t;
	while (t--) {
		int ans = 1;
		cin >> n;
		map<string, int> clothes;
		while (n--) {
			cin >> outfit >> outfit_type;
			clothes[outfit_type]++; // 그 종류의 옷 개수 + 1
		}
		// 연산
		for (auto iter = clothes.begin(); iter != clothes.end(); iter++) {
			ans *= (iter->second + 1); // 입을 수 있는 옷의 종류(iter->second) + 아무것도 입지 않는 경우(1)
		}
		// for (auto keys : clothes) { // map의 key 값으로 interate
		// 	ans *= keys.second + 1;
		// }
		ans--; // 알몸인 경우
		// 출력
		cout << ans << '\n';
	}
	return 0;
}