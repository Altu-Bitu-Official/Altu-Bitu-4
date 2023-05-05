#include <deque>
#include <iostream>

using namespace std;

struct info { // 내구도와 로봇 존재 여부
    int power;  //내구도
    bool is_on; //로봇 존재 여부
};

/* 벨트를 한 칸 회전*/
void rotateBelt(deque<info> &belt, int n) {
    belt.push_front(belt.back());   //마지막 벨트 -> 첫 번째 벨트
    belt.pop_back();    //마지막 벨트 제거
    belt[n - 1].is_on = false; // 로봇이 내리는 위치
}

/* 로봇을 움직일 수 있으면 한 칸 이동*/
void moveRobot(deque<info> &belt, int n) {
    for (int i = n - 2; i >= 0; i--) { // 배열 접근 가능 범위가 0 ~ n-1 인데 다음 칸과 비교해야 하니까 0 ~ n-2
        if (belt[i].is_on && (!belt[i + 1].is_on) && (belt[i + 1].power >= 1)) {
            // 지금 칸에 로봇이 존재하고, 다음 칸에 로봇이 없으며, 다음 칸에 내구도가 남아있을 때
            belt[i].is_on = false;  //현재칸 로봇 없음 처리
            belt[i + 1].is_on = true;   //다음 칸으로 로봇 이동
            belt[i + 1].power--;    //다음 칸 내구도 -1
        }
        belt[n - 1].is_on = false; // 로봇이 내리는 위치
    }
}

/* 올리는 칸에 로봇을 올릴 수 있으면 올림 */
void putRobot(deque<info> &belt) {
    if (!belt[0].is_on && belt[0].power >= 1) {
        // 올리는 칸에 로봇이 존재하지 않고, 내구도가 남아있으면
        belt[0].is_on = true;   //맨 앞칸에 로봇 올리기
        belt[0].power--;    //맨 앞 칸 내구도 -1
    }
}

/* 벨트의 내구도 체크 */
bool checkFinish(deque<info> &belt, int n, int k) {
    int count = 0;  //내구도 0인 벨트 개수
    for (int i = 0; i < 2 * n; i++) {   //전 벨트 검사
        if (belt[i].power == 0) {   //내구도가 0이면
            count++;    //개수 +1
        }
    }

    if (count >= k) {   //내구도 0인 벨트 개수가 k 이상이면
        return true;    //true 반환(과정 종료)
    }
    return false;   //false 반환(과정 이어감)
}

int solution(deque<info> &belt, int n, int k) { 
    int step = 1;   //가장 처음 수행되는 단계는 1번째 단계
    while (true) {
        // 회전
        rotateBelt(belt, n);
        // 이동
        moveRobot(belt, n);
        // 로봇 올리기
        putRobot(belt);

        // 내구도 체크하기
        if (checkFinish(belt, n, k)) {  //내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료
            return step;    //현재 단계 반환
        }
        step++; //단계 증가
    }
}

int main() {
    
    int n, k;   //n : 컨베이어 벨트 길이 k : 내구도 0인 칸 개수 제한
    cin >> n >> k; // 입력
    deque<info> belt(2 * n); // 컨베이어 벨트의 내구도와 로봇 존재 여부 저장
    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i].power;   //i번 칸 내구도 입력
        belt[i].is_on = false;  //로봇 x로 초기화
    }
    
    cout << solution(belt, n, k);   // 연산 & 출력
}