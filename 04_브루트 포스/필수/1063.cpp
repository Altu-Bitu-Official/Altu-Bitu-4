#include "iostream"
#include "utility"

using namespace std;

pair<int, int> replaceCommand(string &command) {
    // command를 int로 변환해 저장할 pair변수
    pair<int, int> command_int = {0, 0};

    // command_int의 first는 x축 이동값, second는 y축 이동값으로 생각하고, 각 command에 따라 값을 더해주거나 빼줌.
    for (int i = 0; i < command.size(); i++) {
        switch (command[i]) {
            case 'R':   // R은 x축으로 1 이동
                command_int.first++;
                break;
            case 'L' :  // L은 x축으로 -1 이동
                command_int.first--;
                break;
            case 'T' :  // T는 y축으로 1 이동
                command_int.second++;
                break;
            case 'B' :  // B는 y축으로 -1 이동
                command_int.second--;
                break;
        }
    }
    return command_int;
}

// 돌이나 킹의 이동 직후 좌표값이 체스판 내에 존재하는지를 반환하는 함수
bool inChessBoard(string temp) {
    if (temp[0] <= 'H' && temp[0] >= 'A' && temp[1] <= '8' && temp[1] >= '1') {
        return true;
    }
    return false;
}

// 오브젝트(돌, 킹)를 움직이는 함수
void moveObject(string &king, string &stone, pair<int, int> command) {
    // 돌과 킹의 이동 후 좌표값을 계산
    string temp_king = {static_cast<char>(king[0] + command.first), static_cast<char>(king[1] + command.second)};
    string temp_stone = {static_cast<char>(king[0] + command.first * 2),
                         static_cast<char>(king[1] + command.second * 2)};

    // 만약 이동한 킹의 좌표값이 원래 돌의 좌표와 같다면
    // 돌도 움직여야하는 상황
    if (temp_king == stone) {
        // 킹과 돌의 이동 후 좌표값이 체스판 밖에 있다면 return
        if (!(inChessBoard(temp_king) && inChessBoard(temp_stone))) {
            return;
        }
        // 체스판 내에 있다면 킹과 돌을 모두 움직여준다.
        king = temp_king;
        stone = temp_stone;
        return;
    }

    // 킹만 움직이는 상황
    // 킹의 이동 후 좌표값이 체스판 내에 있다면 킹을 움직여준다.
    if ((inChessBoard(temp_king))) {
        king = temp_king;
    }
}

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string king, stone, command;
    int n;
    pair<int, int> command_int;

    // 입력
    cin >> king >> stone >> n;

    // 연산
    for (int i = 0; i < n; i++) {
        cin >> command; // 커맨드 입력받기
        command_int = replaceCommand(command);  // 커맨드를 string에서 pair<int,int>로 형태 수정
        moveObject(king, stone, command_int);   // 돌, 킹을 움직인다.
    }

    // 출력
    cout << king << "\n" << stone;
}