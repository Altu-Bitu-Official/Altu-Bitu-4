#include <iostream>
#include <vector>

using namespace std;

int main() {
	// 입출력 속도 향상
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	long velocity = 0;
	
	// 입력
	cin >> n;
	vector<long> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	
	// 연산
	while (n--) {	// 뒤에서부터 속도 확인
		if (velocity <= v[n]) {
			velocity = v[n];
		}
		
		else {
			if (velocity % v[n] != 0) {
				velocity = v[n] * (velocity / v[n] + 1);	// 가장 작은 양의 정수배 구하기
			}						
		}
	}

	// 출력
	cout << velocity << '\n';

	return 0;
}