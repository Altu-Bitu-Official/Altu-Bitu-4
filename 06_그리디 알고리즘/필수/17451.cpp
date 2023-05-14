#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

/*
* 힌트: 자료형마다 값의 범위가 정해져 있다는걸 명심하세요. 어디에서부터 속도를 확인하는 게 더 유리할까요?
* 
* 마지막 행성부터 시작하여, 출발속도가 현재 행성의 필요속도의 배수면서도 증가하도록 만든다.
*/

int main() {
	int n;
	vector<double> planet;
	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		double input;
		cin >> input;
		planet.push_back(input);
	}

	// 연산
	double ans = 1;
	for (int i = n - 1; i >= 0; i--) {
		ans = ceil(ans / planet[i]) * planet[i];
	}

	// 출력
	cout << (long long)ans;
}