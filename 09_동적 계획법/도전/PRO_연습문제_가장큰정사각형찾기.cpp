#include <iostream>
#include <vector>

using namespace std;

int dr[3] = { -1,-1,0 };
int dc[3] = { -1,0,-1 };

//왼, 위, 왼쪽위 대각선 중 최솟값 반환
int getMin(int r, int c, vector<vector<int>>& board) {
    int min_num = 10000;
    for (int i = 0; i < 3; i++) {
        min_num = min(min_num, board[r + dr[i]][c + dc[i]]);
    }
    return min_num;
}

int solution(vector<vector<int>> board) {
    int answer = 0;

    int r = board.size();
    int c = board[0].size();

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (i > 0 && j > 0 && board[i][j] == 1) {
                board[i][j] = getMin(i, j, board) + 1;
            }
            //answer를 정사각형의 한 변의 길이의 최댓값으로 갱신
            answer = max(answer, board[i][j]);
        }
    }
    return answer * answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    //입력
    int r, c;
    cin >> r >> c;

    vector<vector<int>> board(r, vector<int>(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }

    //연산 & 출력
    cout << solution(board);

    return 0;
}