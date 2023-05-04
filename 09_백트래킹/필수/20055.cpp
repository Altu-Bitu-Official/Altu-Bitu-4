#include <deque>
#include <iostream>

using namespace std;

struct info {  //구조체 사용
    int power; //내구도
    bool is_on; //로봇의 존재 여부
};

void rotateBelt(deque<info> &belt, int n) { //벨트를 한칸 회전하는 함수. 반환할 필요 없음
    belt.push_front(belt.back()); //가장 마지막에 있는 요소를 앞에다가 추가
    belt.pop_back(); //가장 마지막에 있는 요소를 없애기
    belt[n - 1].is_on = false; // 로봇이 존재한다면 false로 바꿔주기
}

/* 로봇을 움직일 수 있으면 한 칸 이동*/
void moveRobot(deque<info> &belt, int n) {
    for (int i = n - 2; i >= 0; i--) { // 배열 접근 가능 범위가 0 ~ n-1 인데 다음 칸과 비교해야 하니까 0 ~ n-2
        if (belt[i].is_on && (!belt[i + 1].is_on) && (belt[i + 1].power >= 1)) { // 현재 칸에 로봇이 존재하고, 다음 칸에 로봇이 없고, 다음 칸에 내구도가 남아있을 때
            belt[i].is_on = false; //한칸을 움직였으니깐 false로
            belt[i + 1].is_on = true; //다음 칸에 존재여부를 true로 
            belt[i + 1].power--;
        }
        belt[n - 1].is_on = false; // 로봇이 내려줄때
    }
}

/* 올리는 칸에 로봇을 올릴 수 있으면 올림 */
void putRobot(deque<info> &belt) {
    if (!belt[0].is_on && belt[0].power >= 1) { // 올리는 칸에 로봇이 존재하지 않고, 내구도가 남아있으면 로봇 추가
        belt[0].is_on = true; //로봇 존재하므로 true
        belt[0].power--; //내구도 감소
    }
}

/* 벨트의 내구도 체크 */
bool checkFinish(deque<info> &belt, int n, int k) {
    int count = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (belt[i].power == 0) { //내구도가 0일때 +1
            count++;
        }
    }

    if (count >= k) {
        return true;
    }
    return false;
}

int solution(deque<info> &belt, int n, int k) {
    int step = 1;
    while (true) {
        // 회전
        rotateBelt(belt, n); //회전할때
        // 이동
        moveRobot(belt, n); //이동할때
        // 로봇 올리기
        putRobot(belt); //로봇을 올릴때

        if (checkFinish(belt, n, k)) {
            return step; //내구도 체크
        }
        step++;
    }
}

int main() {
    // 입력
    int n, k;
    cin >> n >> k;
    deque<info> belt(2 * n); // 컨베이어 벨트의 내구도와 로봇 존재 여부 저장(자료구조 선언)
    for (int i = 0; i < 2 * n; i++) {
        cin >> belt[i].power; //입력받기(내구도)
        belt[i].is_on = false; //로봇의 존재 여부는 false로 해놓기
    }
    // 연산 & 출력
    cout << solution(belt, n, k);
}