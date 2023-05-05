#include<iostream>
#include<vector>

using namespace std;
/*
 * 큰 가치의 동전부터 사용하여 거슬러주면 되므로 그리디 알고리즘 이용
 * 동전 사용할 때마다 동전 개수와 남은 금액 갱신, 남은 금액 0 될 때까지 반복
 */
int main() {
	int n, k, cnt = 0; //cnt: count(필요한 동전 개수)
	// 입력
	cin >> n >> k;
	vector<int> val(n); //동전 n종류의 값 입력받을 벡터
	for (int i = 0; i < n; i++) {
		cin >> val[i];
	}
	// 연산
	for (int i = n - 1; i >= 0; i--) { //큰 가치의 돈부터 사용
	    cnt += k / val[i]; //동전 개수 갱신: 남은 금액/동전 가치 더하기
	    k %= val[i]; //남은 금액 갱신: 동전 사용하고 남은 금액으로(나머지 연산자)
        }
	// 출력
	cout << cnt;

    return 0;
}
