#include <iostream>
#include <deque>

using namespace std;

typedef pair<int, bool> pib;

//검사하고 싶은 정수와 cnt를 받아, 정수가 0일 시 cnt를 증가시키는 함수
void checkZero (int n, int& cnt) {
    if (n == 0) {
        cnt++;
        return;
    }
    else {
        return;
    }
}
//덱과 cnt를 받아, 벨트를 규칙에 따라 이동하며 내구도가 0인 칸을 발견할 시 cnt를 증가시키고, 그 cnt를 반환하는 함수
int moveBelt(deque<pib>& dq, int cnt) {
    int len = dq.size();
    //벨트 한 칸 옮기기
    dq.push_front(dq.back());
    dq.pop_back();

    //로봇 내리기
    if (dq[len/2-1].second) {
        dq[len/2-1].second = false;
    }

    //n-1칸에서 한 칸 이동해 n에 도착하는 경우 ->  n 도달 즉시 내림.
    if (dq[len/2-2].second && dq[len/2-1].first >=1) {  // n-1칸에 로봇이 있고, 옮길 수 있을 시
        dq[len/2-2].second = false;
        dq[len/2-1].first--;
        checkZero(dq[len/2-1].first, cnt);
    }

    //로봇 이동하기
    for (int i = len/2-2; i >= 0; i--) {    // n칸부터는 로봇이 없고, n-1칸은 이미 옮김 -> n-2칸부터 0칸까지 탐색.
        if (dq[i].second && dq[i+1].first >= 1 && !dq[i+1].second) {
            dq[i+1].second = true;
            dq[i].second = false;   //로봇 다음 칸에 배정
            dq[i+1].first--;    //내구도 감소
            checkZero(dq[i+1].first, cnt);  //감소된 칸의 내구도가 0일 시 카운트 증가
        }
    }
    if (dq[0].first != 0) {
        dq[0].second = true;    //올리는 칸에 로봇 올림
        dq[0].first--;  //내구도 감소
        checkZero(dq[0].first, cnt);    //내구도 0인지 확인
    }

    return cnt;
}

int main() {
    int n, k, cnt = 0, move_cnt = 0;

    //입력
    cin >> n >> k;
    deque<pib> dq(n*2, {0, false});
    for (int i = 0; i < n*2; i++) {
        cin >> dq[i].first;
    }

    //내구도가 0인 칸의 개수가 k보다 작을 때 벨트 움직이기
    while (cnt < k) {
        cnt = moveBelt(dq, cnt);
        move_cnt++;
    }

    //출력
    cout << move_cnt;

}