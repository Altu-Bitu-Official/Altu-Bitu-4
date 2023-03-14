#include <iostream>
#include <cstring>

using namespace std;

int isOutofBound(char col, int row) {
    if ((col < 'A' && col>'H') || (row < 1 && row>8)) {
        return 1;
    }
    else {
        return 0;
    }
}
int main() {
    char king_loc_col, stone_loc_col; //킹의 위치(열) 돌의 위치(열) 
    int king_loc_row, stone_loc_row, n; //킹의 위치(행) 돌의 위치(행) 움직이는 횟수
    cin >> king_loc_col >> king_loc_row >> stone_loc_col >> stone_loc_row >> n;
    

    while (n--) {
        char king_col_temp = king_loc_col;
        int king_row_temp = king_loc_row;//각 루프를 시작 전 현 위치를 temp변수에 저장.
        char stone_col_temp = stone_loc_col;
        int stone_row_temp = stone_loc_row;
        char input[10] = "";
        cin >> input;

        //R
        if (strcmp(input, "R")) {
            king_col_temp++;
            if (isOutofBound(king_col_temp, king_row_temp)) {
                continue;
            }
            if ((king_col_temp == stone_col_temp) && (king_row_temp == stone_row_temp)) {//가려는 위치에 돌이 있으먄
                stone_col_temp++;
                if (isOutofBound(stone_col_temp, stone_row_temp)) {
                    continue;
                }
            }
            
        }
        //L
        else if (strcmp(input, "L")) {
            king_col_temp--;
            if (isOutofBound(king_col_temp, king_row_temp)) {
                continue;
            }
            if ((king_col_temp == stone_col_temp) && (king_row_temp == stone_row_temp)) {//가려는 위치에 돌이 있으먄
                stone_col_temp--;
                if (isOutofBound(stone_col_temp, stone_row_temp)) {
                    continue;
                }
            }
          
        }
        //B
        else if (strcmp(input, "B")) {
            king_row_temp--;
            if (isOutofBound(king_col_temp, king_row_temp)) {
                continue;
            }
            if ((king_col_temp == stone_col_temp) && (king_row_temp == stone_row_temp)) {//가려는 위치에 돌이 있으먄
                stone_row_temp--;
                if (isOutofBound(stone_col_temp, stone_row_temp)) {
                    continue;
                }
            }
           
        }
        //T
        else if (strcmp(input, "T")) {
            king_row_temp++;
            if (isOutofBound(king_col_temp, king_row_temp)) {
                continue;
            }
            if ((king_col_temp == stone_col_temp) && (king_row_temp == stone_row_temp)) {//가려는 위치에 돌이 있으먄
                stone_row_temp++;
                if (isOutofBound(stone_col_temp, stone_row_temp)) {
                    continue;
                }
            }
           
        }
        //RT
        else if (strcmp(input, "RT")) {
            king_col_temp++;
            king_row_temp++;
            if (isOutofBound(king_col_temp, king_row_temp)) {
                continue;
            }
            if ((king_col_temp == stone_col_temp) && (king_row_temp == stone_row_temp)) {//가려는 위치에 돌이 있으먄
                stone_col_temp++;
                stone_row_temp++;
                if (isOutofBound(stone_col_temp, stone_row_temp)) {
                    continue;
                }
            }
           
        }
        //LT
        else if (strcmp(input, "LT")) {
            king_col_temp--;
            king_row_temp++;
            if (isOutofBound(king_col_temp, king_row_temp)) {
                continue;
            }
            if ((king_col_temp == stone_col_temp) && (king_row_temp == stone_row_temp)) {//가려는 위치에 돌이 있으먄
                stone_col_temp--;
                stone_row_temp++;
                if (isOutofBound(stone_col_temp, stone_row_temp)) {
                    continue;
                }
            }
            
        }
        //RB
        else if (strcmp(input, "RB")) {
            king_col_temp++;
            king_row_temp--;
            if (isOutofBound(king_col_temp, king_row_temp)) {
                continue;
            }
            if ((king_col_temp == stone_col_temp) && (king_row_temp == stone_row_temp)) {//가려는 위치에 돌이 있으먄
                stone_col_temp++;
                stone_row_temp--;
                if (isOutofBound(stone_col_temp, stone_row_temp)) {
                    continue;
                }
            }
            
        }
        //LB
        else {
            king_col_temp--;
            king_row_temp--;
            if (isOutofBound(king_col_temp, king_row_temp)) {
                continue;
            }
            if ((king_col_temp == stone_col_temp) && (king_row_temp == stone_row_temp)) {//가려는 위치에 돌이 있으먄
                stone_col_temp--;
                stone_row_temp--;
                if (isOutofBound(stone_col_temp, stone_row_temp)) {
                    continue;
                }
            }
            
       }
        king_loc_col = king_col_temp;
        king_loc_row = king_row_temp;//이동한 후의 위치를 저장
        stone_loc_col = stone_col_temp;
        stone_loc_row = stone_row_temp;



    }

    cout << king_loc_col << king_loc_row << '\n' << stone_loc_col << stone_loc_row;

}