#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n;//사과나무의 개수
	cin >> n;

	int total = 0;
	int total2 = 0;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		total += k;
		total2 += k / 2;//2를 뿌릴 수 있는 횟수 카운트. 그 외는 1로 채워주면 된다
	}


	if (total % 3 != 0) {
		cout << "NO\n";
	}
	else {
		if (total2 >= total / 3) {//물을 뿌린 총 횟수보다 2를 뿌릴 수 있는 개수가 같거나 커야 한다.
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
}