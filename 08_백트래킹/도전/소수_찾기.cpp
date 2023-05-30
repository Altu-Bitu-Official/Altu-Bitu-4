#include <iostream>
#include <string>
#include <cstring>

using namespace std;

const int MAX_VAL = 1e8;
const int MAX_N = 7;

int n;
int answer = 0;
int nums[MAX_N];
bool is_used[MAX_N];        // is_used[i]: i번 조각을 현재 사용중인지 여부
bool is_counted[MAX_VAL];   // is_counted[i]: i를 카운트 한 적이 있는지 여부

bool isPrime(int x) {
    if (x == 0 || x == 1) {
        return false;
    }
    
    for (long long i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    
    return true;
}

/**
 * 총 N개가 될 때까지 종이 조각을 하나씩 뽑아서 이어붙인다.
 * N개를 뽑는 중간 과정에서 만들어지는 수(1 ~ (N-1)개의 조각으로 만든)도 체크해주면서 지나가면,
 * 종이 조각들로 만들 수 있는 모든 수를 고려하게 된다.
 *
 * cnt: 현재까지 뽑은 종이 조각 개수
 * val: 현재까지 뽑은 종이 조각으로 만든 수
 */
void backtrack(int cnt, int val) {
    // 현재까지 만든 수가 소수인지 체크
    // cnt == 0인 경우는 아직 아무것도 뽑지 않았으므로 내가 만든 수가 아님에 유의
    if (cnt > 0 && !is_counted[val] && isPrime(val)) {
        answer++;
        is_counted[val] = true;
    }
    
    // 재귀 호출 종료 조건: N개를 모두 뽑은 경우
    if (cnt == n) {
        return;
    }
    
    // i: 다음으로 뽑을 수
    for (int i = 0; i < n; i++) {
        if (is_used[i]) {
            continue;
        }
        
        is_used[i] = true;
        backtrack(cnt + 1, val * 10 + nums[i]);
        is_used[i] = false;
    }
}

int solution(string numbers) {
    // 입력 처리
    n = numbers.size();
    for (int i = 0; i < n; i++) {
        nums[i] = numbers[i] - '0';
    }
    
    // 연산
    backtrack(0, 0);
    
    return answer;
}

int main() {
    cout << solution("17");
    
    return 0;
}