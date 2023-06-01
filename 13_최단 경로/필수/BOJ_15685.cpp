#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 100;//격자의 사이즈는 100*100

// 방향: 우(0), 상(1), 좌(2), 하(3)
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

// 1x1 정사각형 개수 계산
int cntSquares(vector<vector<bool>>& plane) {
	int ans = 0;//정사각형 개수 저장할 변수 선언 초기화
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (plane[i][j] && plane[i + 1][j] && plane[i][j + 1] && plane[i + 1][j + 1]) {
                //각각의 좌표에 대하여 현재 위치의 위, 오른쪽, 대각선방향에 값이 존재하면
				ans++;//네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수 하나 증가
			}
		}
	}
	return ans;//정사각형 개수 반환
}

// 평면에 드래곤 커브를 표시
void drawDragonCurve(vector<vector<bool>>& plane, int x, int y, int d, int g) {
	vector<int> direct; // 방향 저장
	plane[y][x] = plane[y + dy[d]][x + dx[d]] = true; // 평면에 표시 (초기화)
	x += dx[d];//방향 새로 설정
	y += dy[d];//방향 새로 설정
	direct.push_back(d);//인자로 받아온 방향을 벡터에 저장
	while (g--) { // 1 ~ g 세대
		int size_d = direct.size();//방향 모음 벡터에 저장된 총 방향의 개수를 변수에 저장
		for (int j = size_d - 1; j >= 0; j--) { // 방향 계산
			int next_d = (direct[j] + 1) % 4;//다음 방향
			x += dx[next_d];//방향 새로 설정
			y += dy[next_d];//방향 새로 설정
			plane[y][x] = true; // 평면에 표시
			direct.push_back(next_d);//새 방향 벡터에 저장
		}
	}
}

/*
* 규칙
* 0 세대: 0
* 1 세대: 0 1
* 2 세대: 0 1 2 1
* 3 세대: 0 1 2 1 2 3 2 1
* ...
* N 세대: concat((N-1세대), ((N-1세대 거꾸로) + 1)%4)
* 평면(좌측 상단이 (0, 0))에 드래곤 커브를 그린 후 정사각형의 개수를 계산
* 드래곤 커브는 평면 밖으로 나가지 않음으로 범위를 확인할 필요 없음
* 1. 0 세대의 드래곤 커브를 먼저 저장 (초기 조건)
* 2. 세대를 거듭하면서 드래곤 커브를 그림 (규칙을 파악하는 것이 중요)
* 3. 드래곤 커브가 그려진 평면 상의 정사각형의 개수 계산 (네 꼭짓점 확인)
*/

int main()
{
	int n, x, y, d, g;
	vector<vector<bool>> plane(SIZE + 1, vector<bool>(SIZE + 1, false)); // 평면
	// 입력
	cin >> n;
	// 연산 & 출력
	while (n--) { // n개의 드래곤 커브 그리기
		cin >> x >> y >> d >> g;//드래곤커프 시작점, 시작방향, 세대 입력
		drawDragonCurve(plane, x, y, d, g);//드래곤커브 실행
	}
	cout << cntSquares(plane) << '\n';//1*1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수를 출력한다.
	return 0;
}