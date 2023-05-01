#include <iostream>
#include <cstdlib>

const int MAX = 21;
using namespace std;

int n; //천제 참가 팀 갯수
int score[MAX][MAX]; //점수배열
bool visited[MAX];//방문확인
int total_t[MAX]; //전체 팀 선택 배열
int team[MAX];
int tmp[MAX];
int min_v = 100000;

void updateMin(int sum1, int sum2) {
	if (abs(sum1 - sum2) <= min_v) {
		min_v = abs(sum1 - sum2);
	}
}

void CalcSum() {
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			sum1 += score[team[i] - 1][team[j] - 1]; //team은 최소값이 1, 최대값이 n 인데 2차원 배열 score은 score[0][0]부터 socre[n-1][n-1]까지 값을 가진다는거 기억해야함
			sum2 += score[tmp[i] - 1][tmp[j] - 1];
		}
	}
	//차이최소값 구하기
	updateMin(sum1, sum2);
}

void backtrack(int cnt) {
	if (cnt == n / 2) {
		int i = 0;
		int j = 0;
		for (int x = 0; x < n; x++) { //전체 인원 중에서
			if (visited[x + 1] == true) { //선택된 값을
				team[i] = x + 1; //새로운 배열에 넣어서 팀 하나를 만든다 
				i++;
			}
			if (visited[x + 1] == false) { //선택되지 않은 값들로 다른 팀 만든다
				tmp[j] = x + 1;
				j++;
			}
		}
		//팀 점수 합 구하기
		CalcSum();

	}
	for (int i = total_t[cnt - 1] + 1; i <= n; i++) {

		//사용
		total_t[cnt] = i;
		visited[i] = true;

		//다음 숫자 뽑기
		backtrack(cnt + 1);

		//반납
		visited[i] = false;
	}
}

int main() {

	cin >> n; //n은 짝수
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> score[i][j];
		}
	}
	//팀 선택(백트래킹)
	backtrack(0);
	cout << min_v;
}