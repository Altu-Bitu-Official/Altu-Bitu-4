#include <iostream>

using namespace std;
const int MAX_N = 8;

int n, m;
int sequence[MAX_N];
bool is_used[MAX_N + 1];

void printSequence() {
    for (int i = 0; i < m; i++) {
        cout << sequence[i] << " ";
    }
    cout << "\n";
}

/**
 * 숫자를 하나씩, 총 M개가 될 때까지 뽑는다.
 *
 * cnt: 현재까지 고른 숫자의 개수
 */
void backtrack(int cnt) {
    // 재귀 호출 종료 조건: M개의 숫자를 다 뽑은 경우
    if (cnt == m) {
        printSequence();
        return;
    }
    
    // i: 고르려는 수
    for (int i = 1; i <= n; i++) {
        // 이미 골랐던 숫자라면, 사용 불가
        if (is_used[i]) {
            continue;
        }
        
        // 사용
        sequence[cnt] = i;
        is_used[i] = true;
        
        // 다음 숫자 고르기
        backtrack(cnt + 1);
        
        // 반납
        is_used[i] = false;
    }
}

int main() {
    // 입력
    cin >> n >> m;

    // 연산
    backtrack(0);
    
    return 0;
}