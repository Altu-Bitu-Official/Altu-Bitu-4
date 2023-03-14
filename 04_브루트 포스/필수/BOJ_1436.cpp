#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, i, cnt = 0;

	// 입력
	cin >> n;

	// 연산
	i = 666;
	
	while (cnt != n) {
		if (to_string(i).find("666") != string::npos) {
			cnt += 1;
		}
		i++;
	}

	// 출력
	cout << i - 1 << '\n';

	return 0;
}