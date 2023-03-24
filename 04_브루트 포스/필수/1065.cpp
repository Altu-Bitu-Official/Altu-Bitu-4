#include <iostream>
#include <string>

using namespace std;

//연산
int cal(int n) {
	int cnt = 0;

	if (n <= 99) {
		return n;
	}

	for (int i = 1; i <= n; i++) {//n까지 반복
		if (i > 99) { // 100 이상 부터는 추가 계산 
			
			string s = to_string(i);

			int diff = (s[1] - '0') - (s[0] - '0'); // 등차 기준 설정

			for (int j = 1; j < s.size() ; j++) {
				if (j == s.size() - 1) {//끝까지 다 돈 것이므로 
					cnt++;
					break;
				}

				if (((s[j + 1] - '0') - (s[j] - '0')) != diff) { // 차이가 다르면 for문 나감 
					break;
				}
			}

		}
		else { // 99까지는 그냥 +1
			cnt++;
		}
	}
	return cnt;
}

int main()
{
	int n, result;
	//입력 
	cin >> n;

	//연산
	result = cal(n);

	//출력 
	cout << result;

	return 0;

}