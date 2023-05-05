#include <iostream>
#include <cmath>
#define MAX 20

using namespace std;

int arr[MAX][MAX];
bool ch[MAX];
int res = 1000;
int n;

// 두 팀의 능력치 차이 계산하는 함수
int cal() {
	int s = 0, l = 0;

	for (int i = 0; i < n; i++) {
		if (ch[i]) {
			for (int j = i + 1; j < n; j++) {
				if (ch[j]) {
					s += arr[i][j] + arr[j][i];
				}
			}
		}
		else {
			for (int j = i + 1; j < n; j++) {
				if (!ch[j]) {
					l += arr[i][j] + arr[j][i];
				}
			}
		}
	}
	
	return abs(s - l);
}


void team(int num, int cnt) {	
	if (cnt == n / 2) {		
		if (cal() < res) {	// 능력치 차이 최솟값 갱신하기
			res = cal();
		}
		
		return;
	}

	for (int i = num; i < n-1; i++) {
		if (ch[i] == true) {
			continue;
		}
		ch[i] = true;
		team(i, cnt + 1);
		ch[i] = false;
	}
}

int main() {
	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	// 연산
	team(0, 0);	
	
	// 출력
	cout << res;

	return 0;
}

/*
참고한 글: https://cocoon1787.tistory.com/170

조합을 구하는 과정을 이용해서 팀을 나눌 때, 아래와 같이
start팀: 1, 2, 3 / link팀: 4, 5, 6
start팀: 4, 5, 6 / link팀: 1, 2, 3
같은 구성으로 중복해서 두 번씩 구해지는 것을 피하기 위해 n-1까지만 반복문을 돌린다는 부분을 참고하였습니다.
*/