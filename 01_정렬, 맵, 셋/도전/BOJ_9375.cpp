#include <iostream>
#include <map>

using namespace std;

int main() {
	int t, n;
	string outfit, outfit_type;

	//입력
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		map<string, int> clothes;
		while (n--) {
			cin >> outfit >> outfit_type;
			clothes[outfit_type]++;
		}

		//연산
		int result = 1;
		for (auto iter = clothes.begin(); iter != clothes.end(); iter++) {
			result *= (iter->second + 1);
		}

		//출력
		cout << result - 1 << "\n";
	}

	return 0;
}