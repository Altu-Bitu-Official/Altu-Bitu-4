#include <deque>
#include <iostream>

using namespace std;

struct info { // 내구도와 로봇 존재 여부
    int power; // 내구도
    bool is_on; // 벨트에 로봇이 존재하는가?
};

/* 벨트를 한 칸 회전*/
void rotateBelt(deque<info>& belt, int n) {
    belt.push_front(belt.back()); // back의 벨트를 front로 끌어온다.
    belt.pop_back(); // back의 요소 삭제
    belt[n - 1].is_on = false; // 로봇이 내리는 위치
}

/* 로봇을 움직일 수 있으면 한 칸 이동*/
void moveRobot(deque<info>& belt, int n) {
    for (int i = n - 2; i >= 0; i--) { // 배열 접근 가능 범위가 0 ~ n-1 인데 다음 칸과 비교해야 하니까 0 ~ n-2
        if (belt[i].is_on && (!belt[i + 1].is_on) && (belt[i + 1].power >= 1)) {
            // 지금 칸에 로봇이 존재하고, 다음 칸에 로봇이 없으며, 다음 칸에 내구도가 남아있을 때
            belt[i].is_on = false;
            belt[i + 1].is_on = true; // 다음 위치로 로봇을 옮긴다.
            belt[i + 1].power--; // 옮긴 위치의 내구도 1 감소
        }
        belt[n - 1].is_on = false; // 로봇이 내리는 위치
        // 이동 후에 로봇이 내리는 위치에 오게 된다면 내리는 것까지 고려해야한다.
    }
}

/* 올리는 칸에 로봇을 올릴 수 있으면 올림 */
void putRobot(deque<info>& belt) {
    if (!belt[0].is_on && belt[0].power >= 1) {
        // 올리는 칸에 로봇이 존재하지 않고, 내구도가 남아있으면
        belt[0].is_on = true; // 로봇을 올린다
        belt[0].power--; // 내구도를 감소시킨다
    }
}

/* 벨트의 내구도 체크 */
bool checkFinish(deque<info>& belt, int n, int k) {
    int count = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (belt[i].power == 0) {
            count++;
        }
    }

    if (count >= k) { // 내구도가 0인 벨트가 k개 이상이 되면 중단한다.
        return true;
    }
    return false;
}

int solution(deque<info>& belt, int n, int k) {
    int step = 1;
    while (true) {
        // 회전
        rotateBelt(belt, n);
        // 이동
        moveRobot(belt, n);
        // 로봇 올리기
        putRobot(belt);

        // 내구도 체크하기
        // 로봇이 모두 이동한 뒤 마지막에 체크한다.
        if (checkFinish(belt, n, k)) {
            return step; // true를 리턴하면 중단 -> 리턴하여 main에서 중단한 단계를 출력한다.
        }
        step++; // 계속 다음 단계 진행
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

int main() {
    // 입력
    int n, k;
    cin >> n >> k;
    deque<info> belt(2 * n); // 컨베이어 벨트의 내구도와 로봇 존재 여부 저장
    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i].power;
        belt[i].is_on = false;
    }
    // 연산 & 출력
    cout << solution(belt, n, k);
}