#include <iostream>
using namespace std;

const int SIZE = 15;
int n, ans; // ans는 경우

bool is_queen_in_col[SIZE];
bool is_queen_in_left[2 * SIZE];
bool is_queen_in_right[2 * SIZE];

// 현재 행의 번호 r
void backtrack(int r)
{
    if (r == n)
    { // 종료 조건
        ans++;
        return;
    }
    // 열번호 c
    for (int c = 0; c <= n; c++)
    {
        // 가지치기
        if (is_queen_in_col[c] && !is_queen_in_left[r + c] && !is_queen_in_right[r - c + n])
        {
            //(r,c)에 queen을 놓기
            is_queen_in_col[c] = true;
            is_queen_in_left[r + c] = true;
            is_queen_in_right[r - c + n] = true;

            // 다음행에 대한 퀸 놓기
            backtrack(r + 1);
            // 반납
            is_queen_in_col[c] = false;
            is_queen_in_left[r + c] = false;
            is_queen_in_right[r - c + n] = false;
        }
    }
}
int main()
{ // 입력
    cin >> n;

    backtrack(0);

    cout << ans;
}