#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

//킹이 움직이는 키워드
vector<int> R = {1, 0};
vector<int> L = {-1, 0};
vector<int> B = {0, -1};
vector<int> T = {0, 1};
vector<int> RT = {1, 1};
vector<int> LT = {-1, 1};
vector<int> RB = {1, -1};
vector<int> LB = {-1, -1};
vector<vector<int>> direction = {R, L, B, T, RT, LT, RB, LB};
string name[] = {"R", "L", "B", "T", "RT", "LT", "RB", "LB"};

vector<int> location(){
    vector<int> arr = {0, 0};

    string tmp;
    cin >> tmp;
    arr[0] = tmp[0]-'A' + 1;     //A = 1
    arr[1] = tmp[1]-'0';

    return arr;
}

bool checkBoard(int a, int b){
    if(a > 8 || a < 1 || b > 8 || b < 1){
        return false;
    }
    return true;
}

int checkRock(vector<int>& king, vector<int>& rock, int x, int y){
    //돌이 있다면
    if(king[0]+x == rock[0] && king[1]+y == rock[1]){
        //돌을 움직였을 때 체크판 범위 체크
        if(checkBoard(rock[0]+x, rock[1]+y)){
            //범위를 벗어나지 않는다면 돌과 체스 옮기기
            rock[0] += x;
            rock[1] += y;
            king[0] += x;
            king[1] += y;
            return 1;
        }
        //범위를 넘어서는 경우
        return -1;
    }
    //돌이 없다면
    return 0;
}

void moveKing(vector<int>& king, vector<int>& rock, int n){
    string m;
    while(n--){
        //입력
        cin >> m;

        for(int i=0; i<8; i++){
            if(name[i] == m){
                //키워드에 해당하는 이동 저장
                int x = direction[i][0];
                int y = direction[i][1];
                
                //돌 체크
                int cr = checkRock(king, rock, x, y);
                //돌이 있으면
                if(cr){
                    break;
                }
                //돌이 없으면
                if(cr == 0){
                    //체스판 범위 검사
                    if(checkBoard(king[0]+x, king[1]+y)){
                        //이동
                        king[0] += x;
                        king[1] += y;
                    }
                    else{
                        break;
                    }
                }
                //돌이 있지만 범위를 넘어서는 경우
                break;
            }
        }
    }
}

int main()
{
    int n;
    //입력
    vector<int> king = location();
    vector<int> rock = location();
    cin >> n;

    //킹 움직이기
    moveKing(king, rock, n);

    cout << char(king[0]+'A'-1) << king[1] << "\n";
    cout << char(rock[0]+'A'-1) << rock[1];
}