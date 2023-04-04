#include<iostream>
#include<vector>

using namespace std;
typedef pair<int, int>pi;
const int a = 19;

//왼->오, 위->아래로 입력이 들어오므로 실질적으로 살펴봐야할 것은
//아래, 오른쪽 위 대각선, 오른쪽수평, 오른쪽 아래 대각선 :이렇게 4방향
pi is_five(int row, int col, vector<vector<int>>& omok) {
	int dr[4] = {0, 1, 1, 1};
	int dc[4] = {-1, 0, -1, 1};

	for (int i = 0; i < 4; i++) {
		int num = 1;//일단 돌이 하나 주어지므로 1부터 시작
		int nr = row; int nc = col;
		while (omok[nr][nc] == omok[nr + dr[i]] [nc + dc[i]]) {
			if (nr + dr[i] >= 0 && nr + dr[i] < a && nc + dc[i] >= 0 && nc + dc[i] < a) {
				num++;
				nr += dr[i]; nc += dc[i];
			}
			else {
				break;
			}
		}
		if (num ==5) {
			return {row, col};
			break;
		}
		else {
			continue;
		}
	}
	return { -1, -1 }; //이기지 못했을 떄는 -1,-1을 리턴
}

int main() {
	vector<vector<int>> omok;
	omok.assign(a, vector<int>(a, 0));
	
	vector<pi>black;
	vector<pi>white;

	//바둑알을 입력 받음
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < a; j++) {
			cin >> omok[i][j];
			if (omok[i][j] == 1) {
				black.push_back({ i,j });//흑톨 위치 저장
			}
			else if (omok[i][j] == 2) {
				white.push_back({ i, j });//백돌 위치 저장
			}
		}
	}

	for (int i = 0; i < black.size(); i++) {
		pi five = is_five(black[i].first, black[i].second, omok);
		if (five.first != -1 && five.second != -1) {
			cout << 1 << "\n" << five.first+1 << " " << five.second+1;
			//위치를 실제론 0~18로 사용했으므로 출력할 땐 +1을 붙여줌
			return 0;//둘다 오목을 완성한 경우는 없으므로 이긴게 확인 됐으면 바로 프로그램 종료
		}
		else {
			continue;
		}
	}

	for (int i = 0; i < white.size(); i++) {
		pi five = is_five(white[i].first, white[i].second, omok);
		if (five.first != -1 && five.second != -1) {
			cout << 2 << "\n" << five.first+1 << " " << five.second+1;
			return 0;
		}
		else {
			continue;
		}
	}

	cout << 0;//아직 승부가 결정되지 않았으므로(흑 백 둘다 -1,-1리턴) 0출력
	return 0;
}