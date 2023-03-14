#include <iostream>

using namespace std;

// 들어온 입력 방향에 따라 좌표를 이동하는 함수
void oper(const string& str, string& coor) {
    if (str == "R") {
        coor[0]++;
    }
    else if (str == "L") {
        coor[0]--;
    }
    else if (str == "B") {
        coor[1]--;
    }
    else if (str == "T") {
        coor[1]++;
    }
    else if (str == "RT") {
        coor[0]++; coor[1]++;
    }
    else if (str == "LT") {
        coor[0]--; coor[1]++;
    }
    else if (str == "RB") {
        coor[0]++; coor[1]--;
    }
    else if (str == "LB") {
        coor[0]--; coor[1]--;
    }
}

// 들어온 입력방향으로 좌표가 이동할 수 있는지 여부를 확인하는 함수
bool checkCanMove(const string& str, string& coor) {
    if (str == "R") {
        if (coor[0] == 'H') {
            return false;
        }
    }
    else if (str == "L") {
        if (coor[0] == 'A') {
            return false;
        }
    }
    else if (str == "B") {
        if (coor[1] == '1') {
            return false;
        }
    }
    else if (str == "T") {
        if (coor[1] == '8') {
            return false;
        }
    }
    else if (str == "RT") {
        if (coor[0] == 'H' || coor[1] == '8') {
            return false;
        }
    }
    else if (str == "LT") {
        if (coor[0] == 'A' || coor[1] == '8') {
            return false;
        }
    }
    else if (str == "RB") {
        if (coor[0] == 'H' || coor[1] == '1') {
            return false;
        }
    }
    else if (str == "LB") {
        if (coor[0] == 'A' || coor[1] == '1') {
            return false;
        }
    }
    return true;
}

// 전체적인 이동 과정을 담당하는 함수
void move(const string& str, string& k_coor, string& s_coor) {
    string k_coor_t = k_coor;
    if (checkCanMove(str, k_coor_t)) {  // 킹이 움직일 수 있을 때
        oper(str, k_coor_t);
    }
    else {
        return;
    }

    if (k_coor_t == s_coor) {   // 킹과 돌의 위치가 같을 때
        if (checkCanMove(str, s_coor)) {
            oper(str, s_coor);
        }
        else {
            return;
        }
    }
    k_coor = k_coor_t;  // 임시좌표를 진짜 좌표에 대입
}

int main() {
    int n;
    string k_coor, s_coor, str; 

    //입력
    cin >> k_coor;
    cin >> s_coor;

    cin >> n;

    while(n--) {
        cin >> str;
        move(str, k_coor, s_coor);
    }
    //출력
    cout << k_coor << '\n' << s_coor;
}