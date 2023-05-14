#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX_N = 11;
const int MAX_ANS = 200 * 15;

int getScore(int r, int c, vector<vector<int>> gr) {
	return gr[r - 1][c] + gr[r][c - 1] + gr[r + 1][c] + gr[r][c + 1] + gr[r][c];
}

int solution(int n, vector<vector<int>> gr) {
	int answer = MAX_ANS;
	int r1, c1, r2, c2, r3, c3;
	n -= 2;

	for (int i = 0; i < n * n; i++) {  //씨앗을 심을 세 곳의 할당값(r,c)을 선택 
		r1 = i / n + 1; c1 = i % n + 1; // 할당값으로 행과 열 계산
        for (int j = 0; j < n * n; j++) {
			r2 = j / n + 1; c2 = j % n + 1;
			if (abs(r1 - r2) + abs(c1 - c2) <= 2) { 
				continue; //겹치는 경우 제외
			} 
			for (int t = 0; t < n * n; t++) {
				r3 = t / n + 1; c3 = t % n + 1;
				if (abs(r1 - r3) + abs(c1 - c3) <= 2 || abs(r2 - r3) + abs(c2 - c3) <= 2) {
					continue;//겹치는 경우 제외 
				} 
				answer = min(answer, getScore(r1, c1, gr) + getScore(r2, c2, gr) + getScore(r3, c3, gr)); //합산
			}
		}
	}
	return answer;
}
/* 꽃길 14620
 * 테투리를 제외한 칸 (n-2) * (n-2) 칸 중에 3칸을 고르면 됩니다.
 * 3칸 중 어떤 두 칸 (r1,c1), (r2,c2)가 abs(r1 - r2) + abs(c1 - c2) <= 2 인 경우를 제외시키면 됩니다.
 *! 칸을 고를 때, (n-2) * (n-2) 크기의 판에 순서대로 0 ~ (n-2)*(n-2) - 1 만큼의 숫자를 할당했다고 가정합시다.
 *! 그러면 어떤 칸이 x (0 <= x < (n-2)*(n-2))값을 가진다면, 그 칸의 행(r)은 x / (n-2) + 1 이고 열(c)은 x % (n-2) + 1 입니다.
 *! 이 방법이 어렵다면 6중 반복문으로 행과 열을 골라주어도 됩니다.
 */
int main()
{
	int n;
	vector<vector<int>> gr(MAX_N, vector<int>(MAX_N));
	//입력
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> gr[i][j];
		}
	}
	//연산 & 출력
	cout << solution(n, gr);
	return 0;
}