//프로그래머스 lv.2 가장 큰 정사각형 찾기
#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = board[0][0];
    int row = board.size();
    int col = board[0].size();
    for(int i = 1; i < row; i++){
        for(int j = 1; j < col; j++){
            if(board[i][j]!=0) {
                board[i][j] = min(board[i-1][j-1], min(board[i][j-1], board[i-1][j]))+1;
                if(answer < board[i][j]){
                    answer = board[i][j];
                }
            }
        }
    }

    return answer*answer;
}
