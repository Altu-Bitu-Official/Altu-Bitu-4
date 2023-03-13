#include <iostream>
#include <string>

using namespace std;

int hanSu(int n) {
	int cnt = 0; //한수의 개수
	for (int i = 1; i <= n; i++) {
		string num = to_string(i);
		int diff = num[1] - num[0]; //공차
		bool check = true; //등차수열 여부
		for (int j = 2; j < num.size(); j++) {
			//공차가 달라지는 경우에는 등차수열 아님
			if (num[j] - num[j - 1] != diff) { 
				check = false;
				break;
			}
		}
		//등차수열인 경우에 한수의 개수 늘리기
		if (check) {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;

	//연산 & 출력
	cout << hanSu(n);

	return 0;
}