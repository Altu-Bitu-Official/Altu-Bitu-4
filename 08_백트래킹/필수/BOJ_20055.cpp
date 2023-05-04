#include <deque> // 덱을 사용하기 위한 헤더
#include <iostream> // 입출력을 위한 헤더 
using namespace std;
// 로봇을 한 칸씩 옮겨 올리는 위치에 로봇을 올려 건너편으로 옮김 

/* 1번: 올리는 위치, N번: 내리는 위치
* 로봇 이동 시 이동한 칸의 내구도는 -1
* 로봇이 이동하려면 이동하려는 칸에 로봇이 없고 내구도가 1 이상이어야 함
* 내구도가 0인 칸의 개수가 k이상이면 종료하고 그렇지 않으면 1번으로 이동
* 몇 단계 진행 중일 때 종료됐는지 출력
*/

struct info { // 내구도와 로봇 존재 여부를  구조체
    int power; // 내구도 
    bool is_on; // 로봇 존재 여부
};

/* 벨트를 한 칸 회전*/
void rotateBelt(deque<info>& belt, int n) { // 벨트 인자와 칸 길이 입력
    // 로봇 한 칸 이동
    belt.push_front(belt.back()); // 맨 마지막에 있는 원소를 맨 앞에 추가 후
    belt.pop_back(); // 맨 마지막 원소 삭제 
    belt[n - 1].is_on = false; // 로봇이 내리는 위치에 있었으면 내려줌
}

/* 로봇을 움직일 수 있으면 한 칸 이동*/
void moveRobot(deque<info>& belt, int n) { // 벨트 인자와 칸 길이 입력
    for (int i = n - 2; i >= 0; i--) { // 배열 접근 가능 범위가 0 ~ n-1 인데 다음 칸과 비교해야 하니까 0 ~ n-2
        if (belt[i].is_on && (!belt[i + 1].is_on) && (belt[i + 1].power >= 1)) {
            // 지금 칸에 로봇이 존재하고, 다음 칸에 로봇이 없으며, 다음 칸에 내구도가 남아있을 때
            belt[i].is_on = false; // 로봇 이동 -> 지금 있던 칸은 false(로봇 없음)로 변경 
            belt[i + 1].is_on = true; // 다음 칸은 true (로봇이 존재함)으로 변경 
            belt[i + 1].power--; // 다음 칸의 내구도 -1 
        }
        belt[n - 1].is_on = false; // 이동한 칸이 로봇이 내리는 위치였다면 로봇을 내려줌
    }
}

/* 올리는 칸에 로봇을 올릴 수 있으면 올림 */
void putRobot(deque<info>& belt) { // 벨트 인자를 입력
    if (!belt[0].is_on && belt[0].power >= 1) {
        // 올리는 칸에 로봇이 존재하지 않고, 내구도가 남아있으면
        belt[0].is_on = true; // 올리는 칸을 true (로봇 존재함)로 변경 
        belt[0].power--; // 올리는 칸의 내구도 -1
    }
}

/* 벨트의 내구도 체크 */
bool checkFinish(deque<info>& belt, int n, int k) { // 벨트 인자, 벨트 길이, k 입력
    int count = 0; // count 변수 0으로 설정
    for (int i = 0; i < 2 * n; i++) { // 내구도가 0인 칸 세기
        if (belt[i].power == 0) { //해당 칸이 내구도가 0이면 
            count++; // count +1
        }
    }

    if (count >= k) { // 내구도가 0인 칸이 k개 이상이면 
        return true; // true 반환
    }
    return false; // k개 미만이면 false 반환
}

int solution(deque<info>& belt, int n, int k) {  // 벨트 인자, 벨트 길이, k 입력
    int step = 1; // 단계 수 셀  변수 
    while (true) {
        // 회전
        rotateBelt(belt, n);
        // 이동
        moveRobot(belt, n);
        // 로봇 올리기
        putRobot(belt);

        // 내구도 체크하기
        if (checkFinish(belt, n, k)) { // 내구도가 0인 칸이 k개 이상이면 
            return step; // 단계 수 반환 후 종료
        }
        step++; // k개 미만이면 단계 수 증가 후 반복문 계속 진행
    }
}


/**
 * [컨베이어 벨트 위의 로봇 문제]
 * 1. 벨트가 각 칸 위의 로봇과 함께 한 칸 회전
 * 2. 가장 먼저 벨트에 올라간 로봇부터, 벨트 회전 방향으로 한 칸 이동할 수 있다면 이동
 *    (이동가능: 이동하려는 칸에 로봇이 없고, 그 칸의 내구도가 1 이상이어야 함)
 * 3. 올리는 위치에 있는 칸의 내구도가 0이 아니면 올리는 위치에 로봇 올림
 * 4. 내구도가 0인 칸의 개수가 k개 이상이라면 과정 종료. 그렇지 않다면 1로 돌아감
 * -> 1 ~ 3까지가 1단계
 *
 * [문제 풀이]
 * 회전과 관련이 깊은 자료구조 deque를 사용하여 풀이
 *
 * 1번 벨트 회전: 벨트의 마지막 원소를 벨트 처음에 넣기
 * 2번 로봇 이동: 가장 먼저 올라간 로봇부터 고려해야 하므로 (내리는 위치 - 1)부터 (올리는 위치)까지 검사
 *               -> 로봇 옮기는거 가능하면 존재여부 체크하고 내구도 감소
 * 3번 로봇 추가: 올리는 위치 칸 내구도 0이 아니라면 해당 칸 로봇 존재 여부 체크 + 내구도 감소
 *
 *
 * >> 주의: 칸 번호를 1번이 아닌 0번부터 시작하는 것으로 관리하고 있기 때문에, n번 칸이 아니라 n-1번 칸이 내리는 위치 <<
 */

int main() { // 가장 먼저 실행되는 main 함수 
    // 입력
    int n, k; // 컨베이어 벨트 길이, 내구도 0인 칸의 개수 제한하는 변수 
    cin >> n >> k; // 입력
    deque<info> belt(2 * n); // 컨베이어 벨트의 내구도와 로봇 존재 여부 저장
    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i].power; // 벨트의 내구도 입력 
        belt[i].is_on = false; // 로봇의 존재여부 false로 초기 설정
    }
    // 연산 & 출력
    cout << solution(belt, n, k); // solution 함수 호출하여 연산
}