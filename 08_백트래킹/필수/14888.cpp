#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;    //int의 최대값
const int MAX_N = 11;   //문제에서 주어진 수의 최대 개수
const int ADD = 0, SUB = 1, MUL = 2, DIV = 3;   //배열 속 연산자 위치
const int EXP_NUM = 4;  //연산자 개수

int n;  //수의 개수
int nums[MAX_N];    //주어진 a의 개수
int expression[EXP_NUM];    //연산자 저장 배열
int max_val = -INF, min_val = INF;  //int의 최대, 최소

void backtrack(int cnt, int curr_val) {
    if (cnt == n - 1) {     //(N-1)개의 연산자를 다 뽑은 경우
        max_val = max(max_val, curr_val);   //만들 수 있는 식의 결과의 최댓값 저장   
        min_val = min(min_val, curr_val);   //만들 수 있는 식의 결과의 최솟값 저장
        return; //재귀 종료
    }
    
    for (int i = 0; i < EXP_NUM; i++) { // i: 연산자 번호
        if (expression[i] == 0) {   // 사용할 연산자가 남아있지 않으면
            continue;   //사용 불가
        }
        
        // 연산자 사용
        expression[i]--;
        //새로운 합 = 0으로 초기화
        int new_sum = 0;
        switch (i) {    //ADD = 0, SUB = 1, MUL = 2, DIV = 3
            case ADD:   //0일 경우
                new_sum = curr_val + nums[cnt + 1]; //기존 값에 더하기
                break;
            case SUB:   //1일 경우
                new_sum = curr_val - nums[cnt + 1]; //기존 값에 빼기
                break;
            case MUL:   //2일 경우
                new_sum = curr_val * nums[cnt + 1]; //기존 값에 곱하기
                break;
            case DIV:   //3일 경우
                new_sum = curr_val / nums[cnt + 1];//기존 값에 나누기
                break;
        }
        
        // 다음 연산자 선택
        backtrack(cnt + 1, new_sum);
        
        // 연산자 반납
        expression[i]++;
    }
}

int main() {
    cin >> n;   //수의 개수 입력
    for (int i = 0; i < n; i++) {   // A1, A2, ..., AN
        cin >> nums[i]; //제공된 수 nums 배열에 저장
    }
    for (int i = 0; i < EXP_NUM; i++) { //연산자 저장
        cin >> expression[i];   //제공된 연산자 개수 expression 배열에 저장
    }

    // 연산
    backtrack(0, nums[0]);

    // 출력
    cout << max_val << '\n' << min_val;
    
    return 0;
}