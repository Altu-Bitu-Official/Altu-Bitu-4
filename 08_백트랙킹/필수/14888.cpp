// 연산자 끼워넣기
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 11;

int n;  // 수의 개수
int answ;   // 연산결과

int nums[MAX];  // 숫자들: 인덱스 0~(n-1)에 n개의 숫자 저장
vector<int> oper;   // 연산자들: 인덱스 1~(n-1)에 (n-1)개의 연산자 저장
bool is_used[MAX];  // 연산자 사용 여부: 인덱스 1~(n-1)에 (n-1)개의 연산자의 사용여부 저장
int sequence[MAX];  // 연산자 조합 결과 저장: 인덱스 1~(n-1)에 (n-1)개의 연산자 저장

const int ADD = 0;  const int SUB = 1;
const int MUL = 2;  const int DIV = 3; 

// 최댓값과 최솟값
// 계산결과는 -10억 이상, 10억 이하
int max_num = 1e9;    int min_num = 1e9;

// op가 0이면 덧셈, 1이면 뺄셈, 2이면 곱셈, 3이면 나눗셈 수행
void calcul(int nu, int op){
    if (op == ADD)
        {answ += nu;}
    if (op == SUB)
        {answ -= nu;}
    if (op == MUL)
        {answ *= nu;}
    if (op == DIV)
        {answ /= nu;}
}

void backtrack(int cnt){
    // 종료조건 : n-1 개의 연산자를 다 뽑은 경우
    // 즉, 1부터 시작한 cnt가 n이 되는 경우
    if (cnt == n){
        // answ 값 초기화
        // sequence에 완성된 가능한 연산자의 배치 1개와 그때의 값 연산한다
        answ = nums[0];
        for (int j=1; j<n; j++){
            calcul(nums[j], sequence[j]);
        }
        // 최댓값과 최솟값 확인
        max_num = max(max_num, answ);
        min_num = min(min_num, answ);

        return;
    }

    // oper[]에 있는 연산자 n-1개의 가능한 배열들을 구한다
    for (int i=1; i<n; i++){
        // 이미 사용한 연산자의 경우, 사용 불가
        if (is_used[i]){
            continue;
        }

        // 연산자 저장
        sequence[cnt] = oper[i];
        is_used[i] = true;

        // 다음으로
        backtrack(cnt+1);

        // 조건 원래대로
        is_used[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  cout.tie(NULL);

    // 입력
    // nums 배열
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> nums[i];
    }
    // oper 벡터: 0은 덧셈, 1은 뺄셈, 2는 곱셈, 3은 나눗셈 연산자
    oper.push_back(0);
    for (int i=0; i<4; i++){
        int temp;
        cin >> temp;
        while (temp--){
            oper.push_back(i);
        }
    }

    // 계산
    backtrack(1);

    // 출력
    cout << max_num << '\n' << min_num;

    return 0;
}