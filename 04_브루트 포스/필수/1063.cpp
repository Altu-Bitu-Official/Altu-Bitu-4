#include <iostream>
#include <utility>

using namespace std;

bool checkValid(char x, char y, int dx, int dy) {
    return (x+dx)>64 && (x+dx)<73 && (y+dy)>48 && (y+dy)<57;
}

int main() {
    string tmp1, tmp2;
    string ch;
    int x, y, n;

    cin >> tmp1 >> tmp2 >> n;

    pair<char, char> king;
    pair<char, char> stone;

    king = make_pair(tmp1[0], tmp1[1]);
    stone = make_pair(tmp2[0], tmp2[1]);

    for(int i=0; i<n; i++) {
        cin >> ch;

        //경우에 따라 이동할 x, y값 할당
        if(ch=="R") {
            x=1;
            y=0;
        } else if(ch=="L") {
            x=-1;
            y=0;
        } else if(ch=="B") {
            x=0;
            y=-1;
        } else if(ch=="T") {
            x=0;
            y=1;
        } else if(ch=="RT") {
            x=1;
            y=1;
        } else if(ch=="LT") {
            x=-1;
            y=1;
        } else if(ch=="RB") {
            x=1;
            y=-1;
        } else if(ch=="LB") {
            x=-1;
            y=-1;
        }

        //옮길 킹 위치가 범위 안이고
        if(checkValid(king.first, king.second, x, y)) {
            //킹 옮긴 위치가 돌 위치랑 겹치면
            if(stone.first==(king.first+x) && stone.second==(king.second+y)){
                //돌 똑같이 옮겼을 때 범위 안이면
                if(checkValid(stone.first, stone.second, x, y)) {
                    //돌도 이동
                    stone.first+=x;
                    stone.second+=y;
                } else {
                    //범위 안에 없으면 둘 다 안 옮김
                    continue;
                }
            }
            //돌 위치랑 안 겹치면 킹만 이동
            king.first+=x;
            king.second+=y;
        }
    }

    cout << king.first << king.second << "\n";
    cout << stone.first << stone.second;

    return 0;
}