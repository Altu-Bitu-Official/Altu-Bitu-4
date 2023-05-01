#include <iostream>

using namespace std;
const int MAX_N = 8;
int n, m; // 재귀함수를 사용하는 경우 전역변수를 사용
int sequence[MAX_N];
bool is_used[MAX_N + 1];

void printSequence()
{
    for (int i = 0; i < n; i++)
    {
        cout << sequence[i] << " ";
    }
    cout << "\n";
}
void backtrack(int cnt) // cnt는 현재까지 뽑은 숫자의 개수 (종료조건이용)
{
    // 종료 조건
    if (cnt == m)
    {
        printSequence();
        return;
    }

    // 고르려는 수 i
    for (int i = sequence[cnt - 1] + 1; i <= n; i++)
    {
        // 이미 골랐던 숫자라면, 사용x
        if (is_used[i])
        {
            continue;
        }
        // 사용
        sequence[cnt] = i;
        is_used[i] = true;

        // 다음 숫자 뽑기
        backtrack(cnt + 1);
    }
}
int main()
{
    // 입력
    cin >> n >> m;

    // 연산
    backtrack(0);
}