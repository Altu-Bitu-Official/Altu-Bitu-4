#include <iostream> // 입출력을 위한 헤더
#include <vector> // 벡터 객체를 사용하기 위한 헤더
using namespace std;

const int MAX_LEN = 19; // 바둑판 가로, 세로 줄 개수 고정값 상수로 선언 
typedef pair<int, int> ci; // 바둑돌의 좌표를 위한 pair 구조체


int dx[4] = { 0, 1, 1, -1 }; // x: 세로, y: 가로 
int dy[4] = { 1, 0, 1, 1 };  // 오른쪽, 위, 오른쪽 위, 오른쪽 아래 

// 시작점 s를 기준으로 오목이 가능한지 확인해주는 함수
bool isValid(vector<vector<int>>& arr, ci s) { // 바둑판의 상태, 시작점의 위치를 인자로 받음
    int cnt, x, y, nx, ny; // 연속하는 돌의 개수 (cnt), 시작점의 위치 (x,y), 탐색 위치 (nx, ny)
    // 시작점 좌표 설정
    x = s.first; // 시작점의 x좌표
    y = s.second; // 시작점의 y좌표

    // 4가지 방향으로 탐색
    for (int i = 0; i < 4; i++) {
        nx = x; // 탐색할 좌표를 
        ny = y; // 처음 위치로 설정

        // cnt가 4개인 경우 오목 성공 (시작점의 돌은 빼고)
        for (cnt = 0; cnt < 5; cnt++) {  // 시작점의 돌을 기준으로 몇개의 돌이 연속하는지 
            nx += dx[i]; // 탐색할
            ny += dy[i]; // 위치의 좌표 갱신

            // 현재 탐색하는 돌이 같은 색 돌이고 바둑판 내에 있다면 
            if ((0 < nx && nx <= MAX_LEN && 0 < ny && ny <= MAX_LEN) && arr[nx][ny] == arr[x][y]) {
                continue; // 반복문 반복
            }
            // 그렇지 않으면 -> break
            break; // 반복문 빠져나옴
        }
        if (cnt == 4) { // 탐색한 방향으로 다섯 알이 연속인 경우
            // 반대 방향도 확인해야 함
            // 역방향 좌표 
            nx = x - dx[i]; // 반대 방향의 탐색할 
            ny = y - dy[i]; // 위치의 좌표 갱신

            // 역방향에는 돌을 놓을 수 없을 때 -> 오목 O
            if (!(0 < nx && nx <= MAX_LEN && 0 < ny && ny <= MAX_LEN)) {
                return true;  // 오목이 가능함 -> true 반환
            }
             // 역방향에 같은 색 돌이 없을 때 -> 오목 O
            else if (arr[nx][ny] != arr[x][y]) {
                return true;  // 오목이 가능함 -> true 반환
            }
           // 역방향에 같은 색 돌이 있을 때 -> 오목 x
        }
    }
    // 시작점을 기준으로 오목 X일때
    return false; // false  반환
}
/** 해당 색의 돌이 게임을 이기면 가장 왼쪽 위에 있는 바둑알의 위치를, {0, 0} 리턴 */
// 어떤 색 돌이 이겼는지 확인해주는 함수
// 해당 색의 돌이 승리한 경우 가장 왼쪽 위의 바둑돌의 위치를 반환
// 해당 색의 돌이 진 경우 {0,0} 반환
ci solution(vector<vector<int>>& arr, vector<ci>& stones) { // 바둑판의 상태, 바둑돌의 좌표 인자로 받음
    for (auto s : stones) { // for (int i=0; i<stones.size(); i++) { ci s = stones[i];}
        // stones에 i번째에 위치하는 좌표를 s에 저장
        if (isValid(arr, s)) { // s를 시작점으로 오목이 가능하다면
            return s;          // s 반환
        }
    }
    //해당 색의 돌이 오목이 불가능하다면 {0, 0} 반환
    return { 0, 0 };
}
/**[백준 2615: 오목]
 * (주의)
 * - 게임에서 이기면 연속된 다섯 개의 가장 왼쪽 위에 있는 바둑알을 출력해야 하므로 탐색 방향에 유의
 * - 여섯 알 이상이 연속이면 오목 X
 * 1. 바둑판의 상태를 입력받아 검은색 돌의 위치와 흰색 돌의 위치를 각각 저장
 * 2. 각각의 돌을 시작점으로 하여 오목을 만들 수 있는지 판단
 * 3. 최대 4개의 돌이 연속하거나, 5개의 돌이 연속했지만 탐색한 반대 방향에도 같은 색의 돌이 있으면 오목 실패
 * 4. 오목에 성공했으면 시작점으로 한 돌의 좌표 반환
 *           실패했으면 {0, 0} 반환
*/
int main() { // 가장 먼저 실행되는 main 함수
    // 입력
    vector<vector<int>> arr(MAX_LEN + 1, vector<int>(MAX_LEN + 1)); 
    // 가로줄, 세로줄 각각 1~19번의 인덱스를 가지는 바둑판
    vector<ci> black_stones, white_stones; // 검은색 돌과 흰색 돌의 좌표 저장

    for (int i = 1; i <= MAX_LEN; i++) { // 세로줄 1~19번
        for (int j = 1; j <= MAX_LEN; j++) { // 가로줄 1~19번 
            cin >> arr[i][j]; // 바둑판에 입력

            if (arr[i][j] == 1) { // 검은색 돌이라면 
                black_stones.push_back({ i, j }); 
                // 해당 좌표를 검은색 돌 좌표 벡터에 저장
            }
            else if (arr[i][j] == 2) { // 흰색 돌이라면 
                white_stones.push_back({ i, j });
                // 해당 좌표를 흰 색 돌 좌표 벡터에 저장
            }
        }
    }

    // 연산
    ci black_win = solution(arr, black_stones);
    // 검은 색 돌이 이긴 경우 가장 왼쪽 위의 좌표 
    ci white_win = solution(arr, white_stones);
    // 흰 색 돌이 이긴 경우 가장 왼쪽 위의  좌표

    // 출력
    if (black_win.first) { // 검은 돌 승리
        cout << "1\n" // 1 출력
            << black_win.first << " " << black_win.second; // 가장 왼쪽 위의 좌표 풀력
    }
    else if (white_win.first) { // 흰 돌 승리
        cout << "2\n" // 2출력
            << white_win.first << " " << white_win.second; // 가장 왼쪽 위의 좌표 출력
    }
    else { // 아직 승부가 결정되지 않은 경우
        cout << "0"; // 0 출력
    }
    return 0; // 메인 함수종료
}