#include <iostream>
#include <string>
using namespace std;

//���� �ȿ� �ִ��� Ȯ��
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

    // R, L, B, T, RT, LT, RB, LB ���� �� x,y�� ��ȭ
    int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
    int dy[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };

    string king, stone, input;
    int n, kx, ky, sx, sy;

    //�Է�
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

        //ŷ �̵�
        int kxl = kx + dx[idx];
        int kyl = ky + dy[idx];

        if (!inRange(kxl, kyl)) { //ŷ�� ������ ����� �������� �ʴ´�
            continue;
        }
        else if (kxl == sx && kyl == sy) { //ŷ�� ���� ��ġ��
            //�� �̵�
            int sxl = sx + dx[idx];
            int syl = sy + dy[idx];

            if (!inRange(sxl, syl)) { //���� ������ ����� �������� �ʴ´�
                continue;
            }
            sx = sxl; sy = syl; //��� ����ϸ� ������ �̵��Ѵ�
        }
        kx = kxl; ky = kyl;
    }

    //���
    cout << (char)(kx + 'A' - 1) << ky << '\n';
    cout << (char)(sx + 'A' - 1) << sy;
    return 0;
}