#include <iostream> // 입출력을 위한 헤더
#include <vector> // 벡터 객체를 사용하기 위한 헤더

using namespace std;

const int SIZE = 100; // 100 x 100 격자이므로 size를 100으로 선언

// 방향: 우(0), 상(1), 좌(2), 하(3)
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

// 1x1 정사각형 개수 계산
int cntSquares(vector<vector<bool>>& plane) { // 격자 인자로 받음
	int ans = 0; // 개수 0으로 초기화
	for (int i = 0; i < SIZE; i++) { // 행
		for (int j = 0; j < SIZE; j++) { //열 탐색
			if (plane[i][j] && plane[i + 1][j] && plane[i][j + 1] && plane[i + 1][j + 1]) {
				// 1x1 정사각형의 네 꼭짓점이 모두 true면 
				ans++; // 개수 증가
			}
		}
	}
	return ans; // 최종 개수 반환
}

// 평면에 드래곤 커브를 표시
void drawDragonCurve(vector<vector<bool>>& plane, int x, int y, int d, int g) {
	// 격자, 시작 x,y 좌표와 시작 방향, 세대를 인자로 받음
	vector<int> direct; // 방향 저장
	plane[y][x] = plane[y + dy[d]][x + dx[d]] = true; // 평면에 표시 (초기화)
	x += dx[d]; // 이동한 x좌표 위치
	y += dy[d]; // 이동한 y좌표 위치
	direct.push_back(d); // 방향을 저장하는 벡터에 입력받은 방향 저장

	while (g--) { // 1 ~ g 세대동안 반복
		int size_d = direct.size(); // 현재까지 저장된 방향의 개수 저장
		for (int j = size_d - 1; j >= 0; j--) { // 방향 계산 (벡터 뒤에서부터)
			int next_d = (direct[j] + 1) % 4; // 다음 방향 계산
			// -> 세대가 증가하면서 방향이 반시계로 변경되기 때문
			x += dx[next_d]; // 이동한 x좌표 위치 갱신 
			y += dy[next_d]; // 이동한 y좌표 위치 갱신
			plane[y][x] = true; // 평면에 표시
			direct.push_back(next_d); // 다음 방향을 벡터에 저장
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

int main() // 제일 먼저 실행되는 main 함수
{
	int n, x, y, d, g; // 드래곤 커브 개수, 드래곤 커브 시작 점, 시작 방향, 세대 
	vector<vector<bool>> plane(SIZE + 1, vector<bool>(SIZE + 1, false)); // 평면
	// 입력
	cin >> n; // 드래곤 커브 개수 입력
	// 연산 & 출력
	while (n--) { // n개의 드래곤 커브 그리기
		cin >> x >> y >> d >> g; // 커브 시작 x좌표, y좌표, 시작 방향, 세대 입력
		drawDragonCurve(plane, x, y, d, g); // 평면에 드래곤 커브 표시한 후
	}
	cout << cntSquares(plane) << '\n'; // 네 꼭짓점이 모두 드래곤 커브인 개수 출력
	return 0; // main 함수 종료
}