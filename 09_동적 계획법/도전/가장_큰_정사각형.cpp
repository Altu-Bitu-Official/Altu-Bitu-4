#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSquare(int row, int col, vector<vector<int>>& board) {
    // dp[i][j]: (i, j)를 우측하단 꼭짓점으로 하는 가장 큰 정사각형의 한 변의 길이
    vector<vector<int>> dp(row + 1, vector<int>(col + 1, 0));
    int ret = 0;
    
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            // 꼭짓점이 0인 경우, 정사각형의 크기는 0
            if (board[i - 1][j - 1] == 0) {
                continue;
            }
            
            // 북서쪽(↖) 정사각형, 북쪽(↑) 정사각형, 서쪽(←) 정사각형으로 쪼갤 수 있음,
            // 그 중 가장 작은 정사각형의 한 변의 길이 X에 맞춰 자른 뒤
            // (i, j)를 꼭짓점으로 한 칸 추가하면 한 변의 길이가 (X+1)인 정사각형이 됨
            dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            ret = max(ret, dp[i][j]); // 최대값 갱신
        }
    }
    
    return ret * ret;
}

/**
 * 정사각형은 다음과 같이 쪼갤 수 있음
 * ex. 4x4 정사각형
 * = (↖ 3x3 정사각형) + (↑ 3x3 정사각형) + (← 3x3 정사각형) + (오른쪽 아래 1x1 정사각형)
 *
 * 1 1 1 1     1 1 1 0     0 1 1 1     0 0 0 0     0 0 0 0
 * 1 1 1 1  =  1 1 1 0  +  0 1 1 1  +  1 1 1 0  +  0 0 0 0
 * 1 1 1 1     1 1 1 0     0 1 1 1     1 1 1 0     0 0 0 0
 * 1 1 1 1     0 0 0 0     0 0 0 0     1 1 1 0     0 0 0 1
 *
 * 따라서 dp[i][j]: (i, j)를 우측하단 꼭짓점으로 하는 가장 큰 정사각형의 한 변의 길이 라고 하면
 * dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]} + 1
 */
int solution(vector<vector<int>> board)
{
    int row = board.size();
    int col = board[0].size();
    
    int answer = maxSquare(row, col, board);

    return answer;
}

int main() {
    vector<vector<int>> board =
    {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 1, 0}
    };
    cout << solution(board);
    
    return 0;
}