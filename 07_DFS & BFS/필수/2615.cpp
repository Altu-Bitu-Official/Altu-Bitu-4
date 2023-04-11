#include <iostream>
#include <vector>

using namespace std;

bool checkRange(int i, int j) {
    return i>=0 && i<19 && j>=0 && j<19;
}

bool isWin(int x, int y, vector<vector<int> > &board, int color) {

    int dr[4] = {1, 0, 1, -1};
    int dc[4] = {0, 1, 1, 1};


    for(int i=0; i<4; i++) {
        int r = x;
        int c = y;

        //가장자리 돌은 직전이랑 비교 안해도 됨 가장자리 아니면 직전 돌 색깔 다른지 확인
        if((r-dr[i]<0||c-dc[i]<0) || (checkRange(r-dr[i],c-dc[i]) && board[r-dr[i]][c-dc[i]]!=color)) {
            int cnt = 1;
            r+=dr[i];
            c+=dc[i];

            //다음 돌 색깔 동일한지 확인하고 동일하면 cnt++
            while(checkRange(r,c) && board[r][c]==color) {
                r+=dr[i];
                c+=dc[i];
                cnt++;
            }

            if(cnt==5) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector<vector<int> > board;
    board.assign(19, vector<int> (19, 0));

    for(int i=0; i<19; i++) {
        for(int j=0; j<19; j++) {
            cin >> board[i][j];
        }
    }

    for(int i=0; i<19; i++) {
        for(int j=0; j<19; j++) {
            //검은돌 1
            if(board[i][j]==1 && isWin(i, j, board, 1)) {
                cout << 1 << "\n" << i+1 << " " << j+1;
                return 0;
            //흰돌 2
            } else if(board[i][j]==2 && isWin(i, j, board, 2)) {
                cout << 2 << "\n" << i+1 << " " << j+1;
                return 0;
            }
        }
    }

    //검은돌 흰돌 다 오목 없으면 0
    cout << 0;
    return 0;
}