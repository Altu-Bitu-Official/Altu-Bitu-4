#include <iostream>
#include <vector>

using namespace std;

//입력 배열과 좌표를 받아 같은 돌 다섯 개가 연속되는지 여부를 확인하는 함수
bool checkFive(const vector<vector<int>>& input, int i, int j) {
    vector<int> dx = {-1, 1, 1, 0}, dy = {1, 0, 1, 1};  //오른쪽 위 대각선, 아래, 오른쪽 아래 대각선, 오른쪽

    if (input[i][j] == 0) {    //0일 때 스킵
        return false;
    }

    for(int k = 0; k < 4; k++) {
        int cnt = 0;
        int nx = i + dx[k], ny = j + dy[k];
        while (nx >= 0 && nx < 19 && ny >= 0 && ny < 19 && input[nx][ny] == input[i][j]) {  //처음 돌과 어느 방향의 다음 돌이 같을 때
            cnt++;
            nx += dx[k];
            ny += dy[k];
            if (cnt == 4) { //같은 돌이 5번 온 경우
                int nnx = i - dx[k], nny = j - dy[k]; //원래 방향의 반대로 처음 위치에서 한 칸씩 옮긴 좌표
                //범위 확인하고, 만약 처음 돌과 같다면 6개 연속 -> break.
                if (nx >= 0 && nx < 19 && ny >= 0 && ny < 19 && input[nx][ny] == input[i][j]) {
                    break;
                }
                if (nnx >= 0 && nnx < 19 && nny >= 0 && nny < 19 && input[nnx][nny] == input[i][j]) {
                    break;
                }
                //아니면 5개 연속이므로 승리.
                cout << input[i][j] << '\n' << i + 1 << ' ' << j + 1;
                return true;
            }
        }
    }
    return false;

}

//입력 배열을 받아 승리 여부를 검사하는 함수
void checkWin(const vector<vector<int>>& input) {
    int i, j;
    for (i = 0; i < 19; i++) {
        for (j = 0; j < 19; j++) {
            if(checkFive(input, i, j)) {    //true일 시 프로그램 종료
                return;
            }
        }
    }
    if (i == 19 && j == 19) {
        cout << 0;
        return;
    }
}

int main() {
    vector<vector<int>> input(19, vector<int> (19, 0));

    //입력
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            cin >> input[i][j];
        }
    }

    checkWin(input);
}