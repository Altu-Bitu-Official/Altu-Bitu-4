// 재귀함수 안에서 정의된 변수들은 계속 선언되어야 하므로 전역변수로 선언해도 괜찮다.
#include <iostream>
#include <vector>

using namespace std;
const int MAX_N = 11;
const int MAX_INT = 1000000000;

int n;
vector<int> nums;        // 숫자를 저장할 벡터
vector<int> op(4, 0);    // 각 연산자의 개수를 저장할 벡터
int sequence[MAX_N - 1]; // 연산자 수 = 숫자의 개수 - 1

int small = MAX_INT; // 최솟값
int big = -MAX_INT;  // 최댓값

int calculate(int n1, int op, int n2) { // n1과 n2를 op로 연산해준다
    switch(op) {
        case 0:
            return n1 + n2;
        case 1: 
            return n1 - n2;
        case 2:
            return n1 * n2;
        case 3:
            return n1 / n2;
    }
}

void completeFormula() { // 식이 하나 완성될 때마다 호출되는 함수
    int sum = nums[0];

    // 뽑힌 연산자마다 계산
    for (int i = 0; i < n - 1; i++) {
        sum = calculate(sum, sequence[i], nums[i+1]);
    }

    if(sum > big) {    // 최댓값 업데이트
        big = sum;
    }
    
    if (sum < small) { // 최솟값 업데이트
        small = sum;
    }
}

void backtrack(int cnt) {
    // 종료 조건: 연산자를 n-1개 뽑았을 때
    if(cnt == n-1) {
        // 식 하나 완성
        completeFormula();
        return;
    }

    // 고르려는 연산자 i
    for (int i = 0; i < 4; i++) {
        // 해당 연산자를 다 썼다면, 사용 불가
        if(!op[i]) {
            continue;
        }

        // 사용
        sequence[cnt] = i;
        op[i]--;

        // 다음 자리 연산자 뽑기
        backtrack(cnt + 1);

        // 반납
        op[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // 입력
    cin >> n;
    nums.assign(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    for(int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    // 연산
    backtrack(0); // cnt는 0부터 시작

    // 출력
    cout << big << '\n' << small;

    return 0;
}