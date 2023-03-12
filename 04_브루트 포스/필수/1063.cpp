#include <iostream>

using namespace std;

int main() {
    string king, stone;
    string ch;
    int x, y, n;

    cin >> king >> stone >> n;

    char king_x=king[0], king_y=king[1];
    char stone_x=stone[0], stone_y=stone[1];

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
        if((king_x+x)>64 && (king_x+x)<73 && (king_y+y)>48 && (king_y+y)<57) {
            //킹 옮긴 위치가 돌 위치랑 겹치면
            if(stone_x==(king_x+x) && stone_y==(king_y+y)){
                //돌 똑같이 옮겼을 때 범위 안이면
                if((stone_x+x)>64 && (stone_x+x)<73 && (stone_y+y)>48 && (stone_y+y)<57) {
                    //돌도 이동
                    stone_x+=x;
                    stone_y+=y;
                } else {
                    //범위 안에 없으면 둘 다 안 옮김
                    continue;
                }
            }
            //돌 위치랑 안 겹치면 킹만 이동
            king_x+=x;
            king_y+=y;
        }
    }

    cout << king_x << king_y << "\n";
    cout << stone_x << stone_y;

    return 0;
}