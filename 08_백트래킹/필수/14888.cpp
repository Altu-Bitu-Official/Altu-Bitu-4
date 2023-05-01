#include<iostream>

using namespace std;

int number[11];
int op[4];
int r_max = -1000000000;
int r_min = 1000000000;
int n;

void calculator(int result, int index) {

	if (index == n) {
		if (result > r_max){
			r_max = result; //더 큰 값을 발견하면 갱신
		}
		if (result < r_min) {
			r_min = result; //더 작은 값을 발견하면 갱신
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			op[i]--;//연산자를 사용하므로 연산자 숫자 -1

			//연산한 뒤 재귀적으로 함수 호출
			if (i == 0) {
				calculator(result + number[index], index + 1);
			}
			else if (i == 1) {
				calculator(result - number[index], index + 1);
			}
			else if (i == 2) {
				calculator(result * number[index], index + 1);
			}
			else {
				calculator(result / number[index], index + 1);
			}

			op[i]++; //다른 경우의 수를 탐색할 것이므로 사용했던 연산자를 다시 복구 시킴
		}
	}
	return;
}

int main() {
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> number[i];
	}
	for (int i = 0; i < 4; i++) {	
		cin >> op[i]; //차례대로 + - * /
	}

	calculator(number[0], 1);

	cout << r_max << "\n";
	cout << r_min;
	
	return 0;

}