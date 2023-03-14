#include <iostream>
#include <string>
using namespace std;

//범위 안에 있는지 확인
bool inRange(int x, int y) {
    if (x <= 0 || x > 8 || y <= 0 || y > 8) {
        return false;
    }
    else {
        return true;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    // R, L, B, T, RT, LT, RB, LB 방향 별 x,y값 변화
    int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
    int dy[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };

    string king, stone, input;
    int n, kx, ky, sx, sy;

    //입력
    cin >> king >> stone >> n;

    kx = king[0] - 'A' + 1;
    sx = stone[0] - 'A' + 1;
    ky = king[1] - '0';
    sy = stone[1] - '0';

    for (int i = 0; i < n; i++) {
        cin >> input;

        int idx = 0;
        if (input == "R") idx = 0;
        else if (input == "L") idx = 1;
        else if (input == "B") idx = 2;
        else if (input == "T") idx = 3;
        else if (input == "RT") idx = 4;
        else if (input == "LT") idx = 5;
        else if (input == "RB") idx = 6;
        else if (input == "LB") idx = 7;

        //킹 이동
        int kxl = kx + dx[idx];
        int kyl = ky + dy[idx];

        if (!inRange(kxl, kyl)) { //킹이 범위를 벗어나면 움직이지 않는다
            continue;
        }
        else if (kxl == sx && kyl == sy) { //킹과 돌이 겹치면
            //돌 이동
            int sxl = sx + dx[idx];
            int syl = sy + dy[idx];

            if (!inRange(sxl, syl)) { //돌이 범위를 벗어나면 움직이지 않는다
                continue;
            }
            sx = sxl; sy = syl; //모두 통과하면 실제로 이동한다
        }
        kx = kxl; ky = kyl;
    }

    //출력
    cout << (char)(kx + 'A' - 1) << ky << '\n';
    cout << (char)(sx + 'A' - 1) << sy;
    return 0;
}