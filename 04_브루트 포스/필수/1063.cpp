#include <iostream>
#include <vector>
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

pair<int, int> location(string tmp){
    pair<int, int> p;
    p.first = tmp[0]-'A' + 1;     //A = 1
    p.second = tmp[1]-'0';
    return p;
}

bool checkBoard(int a, int b){
    if(a > 8 || a < 1 || b > 8 || b < 1){
        return false;
    }
    return true;
}

int checkRock(pair<int, int>& king, pair<int, int>& rock, int x, int y){
    //돌이 있다면
    if(king.first+x == rock.first && king.second+y == rock.second){
        //돌을 움직였을 때 체크판 범위 체크
        if(checkBoard(rock.first+x, rock.second+y)){
            //범위를 벗어나지 않는다면 돌과 체스 옮기기
            rock.first += x;
            rock.second += y;
            king.first += x;
            king.second += y;
            return 1;
        }
        //범위를 넘어서는 경우
        return -1;
    }
    //돌이 없다면
    return 0;
}

void moveKing(pair<int, int>& king, pair<int, int>& rock, int n){
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
                //돌이 있으면 && 돌이 있지만 범위를 넘어서는 경우
                if(checkRock(king, rock, x, y)){
                    break;
                }
                //돌이 없으면
                else{
                    //체스판 범위 검사
                    if(checkBoard(king.first+x, king.second+y)){
                        //이동
                        king.first += x;
                        king.second += y;
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
}

int main()
{
    int n;
    //pair<int, int> king;

    //입력
    string tmp;
    cin >> tmp;
    pair<int, int> king = location(tmp);
    cin >> tmp;
    pair<int, int> rock = location(tmp);
    cin >> n;

    //킹 움직이기
    moveKing(king, rock, n);

    cout << char(king.first+'A'-1) << king.second << "\n";
    cout << char(rock.first+'A'-1) << rock.second;
}