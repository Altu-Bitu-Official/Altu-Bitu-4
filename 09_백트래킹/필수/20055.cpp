#include <deque>
#include <iostream>

using namespace std;

struct info { // 내구도와 로봇 존재 여부
    int power; //power: 내구도 
    bool is_on; //is_on: 로본 존재 여부 
};

/* 벨트를 한 칸 회전*/
//벨트 deque과 belt의 길이를 입력받아 belt deque 수정 
void rotateBelt(deque<info> &belt, int n) {
    belt.push_front(belt.back()); //맨 뒤 -> 맨 앞으로 삽입
    belt.pop_back(); //뒤에 있었던 건 삭제 
    belt[n - 1].is_on = false; // 로봇이 내리는 위치를 false로 변경 
}

/* 로봇을 움직일 수 있으면 한 칸 이동*/
//벨트 deque과 belt의 길이를 입력받아 belt deque 수정 
void moveRobot(deque<info> &belt, int n) {
    for (int i = n - 2; i >= 0; i--) { // 배열 접근 가능 범위가 0 ~ n-1 인데 다음 칸과 비교해야 하니까 0 ~ n-2
        if (belt[i].is_on && (!belt[i + 1].is_on) && (belt[i + 1].power >= 1)) {
            // 지금 칸에 로봇이 존재하고, 다음 칸에 로봇이 없으며, 다음 칸에 내구도가 남아있을 때
            belt[i].is_on = false; //현재 칸의 존재 여부 false로 변경 
            belt[i + 1].is_on = true; //i+1 칸의 존재 여부 true로 변경 
            belt[i + 1].power--; //i+1 칸의 내구도 -1 
        }
        belt[n - 1].is_on = false; // 로봇이 내리는 위치
    }
}

/* 올리는 칸에 로봇을 올릴 수 있으면 올림 */
//벨트 deque과 belt의 길이를 입력받아 belt deque 수정 
void putRobot(deque<info> &belt) {
    if (!belt[0].is_on && belt[0].power >= 1) {
        // 올리는 칸에 로봇이 존재하지 않고, 내구도가 남아있으면
        belt[0].is_on = true; //올리는 칸의 존재 여부 true로 변경 
        belt[0].power--; //그 칸의 내구도 -1
    }
}

/* 벨트의 내구도 체크 */
//belt deque과 n, k 입력받아 내구도 0인 칸의 개수가 k개 이상인지 판단함 
bool checkFinish(deque<info> &belt, int n, int k) {
    int count = 0; //내구도 0인 칸의 개수 count 
    for (int i = 0; i < 2 * n; i++) {//i: 0~2n-1
        if (belt[i].power == 0) {
            count++; //내구도가 0이라면 카운트 +1
        }
    }

    if (count >= k) { //내구도가 0인 칸의 개수가 k개 이상인 경우 
        return true; //true를 리턴 
    }
    return false; //아닌 경우, false를 리턴 
}
//belt deque과 belt 길이 n, k 입력받아 몇 단계를 수행하고 있었는지 리턴 
int solution(deque<info> &belt, int n, int k) {
    int step = 1; //1단계부터 시작 
    while (true) {
        // 회전
        rotateBelt(belt, n);
        // 이동
        moveRobot(belt, n);
        // 로봇 올리기
        putRobot(belt);

        // 내구도 체크하기
        if (checkFinish(belt, n, k)) {
            return step; //값이 1인 경우 당시의 step 단계 값을 리턴함 
        }
        step++; //아닌 경우, while문 계속 실행함 
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
    int n, k; //n: 컨베이어 벨트 길이
              //k: 내구도 판단 정수 
    cin >> n >> k;
    deque<info> belt(2 * n); // 컨베이어 벨트의 내구도와 로봇 존재 여부 저장
    for (int i = 0; i < 2 * n; i++) {//i:0~2n-1 
        cin >> belt[i].power;  
        belt[i].is_on = false; //시작하기 전 전부 존재 여부 false
    }
    // 연산 & 출력
    cout << solution(belt, n, k);
}