#include<iostream>
#include<vector>

using namespace std;
/*
* 1. 한 번 물을 줄 때마다 3씩 나무가 자라므로, 나무 높이의 합(sum)은 3의 배수가 되어야 합니다.
*   (이 때, 물을 주는 횟수 k는 `sum/3`이 됩니다.)
* 2. `홀수+홀수=짝수`, `짝수+짝수=짝수`, `홀수+홀수=짝수` 입니다.
*   따라서 k번 물을 준다면 홀수 높이는 최대 k개만 가능합니다.
*/

void summation(int &sum, int &height){
	sum += height;
}

void countOdd(int &height, int &odd){
	if (height % 2) { //홀수 높이의 개수 세기
		odd++;
	}
}

bool solve(int sum, int odd) {
	if (sum % 3) { //최종 나무 높이의 합이 3의 배수여야 함
		return false;
	}
	if (odd > sum / 3) { // (sum/3)은 물을 주는 횟수
		return false;
	}
	return true;
}
int main() {
	int n, sum = 0, odd = 0;

	// 입력
	cin >> n;

	// 입력 & 연산
	for (int i = 0; i < n; i++) {
		int height;
		cin >> height; 
		summation(sum, height);
		countOdd(height, odd);
	}

	// 연산 & 출력
	solve(sum, odd) ? cout << "YES" : cout << "NO";
	//삼항연산자
	// `condition ? A : B` 형태 => condition이 참인 경우 A 실행(사용), condition이 거짓인 경우 B 실행(사용)
    return 0;
}