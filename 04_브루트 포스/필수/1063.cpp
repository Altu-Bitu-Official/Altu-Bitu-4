/*
8*8크기의 체스판에 왕이 하나 있다. 킹의 현재 위치가 주어진다. 
알파벳 하나와 숫자 하나로 이루어져 있는데, 알파벳은 열을 상징하고, 숫자는 행을 상징한다.
열은 가장 왼쪽 열이 A이고, 가장 오른쪽 열이 H까지 이고, 행은 가장 아래가 1이고 가장 위가 8이다. 
체스판에는 돌이 하나 있는데, 돌과 같은 곳으로 이동할 때는, 돌을 킹이 움직인 방향과 같은 방향으로 한 칸 이동시킨다.
입력으로 주어진 대로 움직여서 킹이나 돌이 체스판 밖으로 나갈 경우에는 그 이동은 건너 뛰고 다음 이동을 한다.

킹과 돌의 마지막 위치를 구하는 프로그램을 작성하시오.
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const string ALPHA = "ABCDEFGH";

void moveChess(vector<int> &param, vector<int> &king, vector<int> &rock) {
    vector<int> king_origin = king; // 원래 위치 저장하고 시작
    vector<int> rock_origin = rock;

    king[0] += param[0];  // king의 위치 param만큼 이동
    king[1] += param[1];

    if(king == rock) {    // 이동한 king의 위치가 rock의 위치와 같으면 rock 이동
        rock[0] += param[0];
        rock[1] += param[1];
    }
    // 체스판의 범위를 넘으면 원래 위치로 되돌림
    if(king[0] > 7 || king[0] < 0 || king[1] > 8 || king[1] < 1 || rock[0] > 7 || rock[0] < 0 || rock[1] > 8 || rock[1] < 1) {
        king = king_origin;
        rock = rock_origin; 
    }
}

void moveByInput(string &move, vector<int> &king, vector<int> &rock) {
    vector<int> param(2);   // 행, 열
    if(move == "R") {       // 한 칸 오른쪽으로
        param[0]++;
    }
    else if(move == "L") {  // 한 칸 왼쪽으로
        param[0]--;
    }
    else if(move == "B") {  // 한 칸 아래로
        param[1]--;
    }
    else if(move == "T") {  // 한 칸 위로
        param[1]++; 
    }
    else if(move == "RT") { // 오른쪽 위 대각선으로
        param[0]++; param[1]++;
    }
    else if(move == "LT") { // 왼쪽 위 대각선으로
        param[0]--; param[1]++;
    }
    else if(move == "RB") { // 오른쪽 아래 대각선으로
        param[0]++; param[1]--;
    }
    else { // LB            // 왼쪽 아래 대각선으로
        param[0]--; param[1]--;
    }
    moveChess(param, king, rock);  // param만큼 king과 rock을 이동시킴
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str1, str2; // 입력 문자열
    int move_num;      // 움직이는 횟수

    vector<int> king(2); // 왕의 위치 [0]: 알파벳 인덱스, [1]: 숫자
    vector<int> rock(2); // 돌의 위치 [0]: 알파벳 인덱스, [1]: 숫자
   
    cin >> str1 >> str2 >> move_num;
    
    int found = 0;
    for(int i = 0; i < ALPHA.size(); i++) { // 알파벳 문자열에서 입력으로 들어온 문자 찾기
        if(ALPHA[i] == str1[0]) {
            king[0] = i;                    // [0]에 알파벳 인덱스 저장
            found++;
        }
        if(ALPHA[i] == str2[0]) {
            rock[0] = i;
            found++;
        }
        if(found == 2) {  // 둘 다 찾았으면 반복문 빠져나감
            break;
        }
    }
    king[1] = str1[1] - '0';                // 숫자 형태로 [1]에 저장
    rock[1] = str2[1] - '0';

    string input; // 이동 입력
    for(int i = 0; i < move_num; i++) {
        cin >> input;
        moveByInput(input, king, rock); // 입력에 따라 king과 rock 이동
    }
    // [0]의 수는 알파벳으로 바꾸어 위치 출력
    cout << ALPHA[king[0]] << king[1] << "\n" << ALPHA[rock[0]] << rock[1]; 
    return 0;
}