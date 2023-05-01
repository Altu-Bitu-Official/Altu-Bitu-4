#include<iostream>
#include <cmath>

const int MAX_N = 12;

int n, m; //재귀함수를 사용해야 할 경우 전역변수 사용
int sequence[MAX_N];
int op[4];
int add, sub, mul, divi;
int min_v = 1000000000;
int max_v = -1000000000;
using namespace std;

void CalcAns(int ans) {
	if (ans >= max_v) {
		max_v = ans;
	}
	if (ans < min_v) {
		min_v = ans;
	}
}


void backtrack(int cnt, int ans) {
	//종료조건: cnt == m
	if (cnt == n) {
		//답 하나 찾음
		CalcAns(ans);
		return;
	}
	//고르려는 연산자
	for (int i = 0; i < 4; i++) {
		if (op[i] <= 0) {
			continue;
		}
		op[i]--;
		switch (i) {
		case 0:
			backtrack(cnt + 1, ans + sequence[cnt]);
			break;
		case 1:
			backtrack(cnt + 1, ans - sequence[cnt]);
			break;
		case 2:
			backtrack(cnt + 1, ans * sequence[cnt]);
			break;
		case 3:
			backtrack(cnt + 1, ans / sequence[cnt]);
			break;
		}
		op[i]++;
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> sequence[i];
	}
	cin >> add >> sub >> mul >> divi;
	op[0] = add;
	op[1] = sub;
	op[2] = mul;
	op[3] = divi;

	backtrack(1, sequence[0]);
	cout << max_v << "\n" << min_v;
}