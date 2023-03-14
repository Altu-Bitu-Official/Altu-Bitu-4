#include <iostream>
#include <string>

using namespace std;

void collision(string &king, string &stone) {

}

void move(string &king, string &stone, const string &inst) {
    string temp_king = king;
    string temp_stone = stone;

    if (inst == "R") {
        king[0] = (char) (king[0] + 1);
    } else if (inst == "L") {
        king[0] = (char) (king[0] - 1);
    } else if (inst == "B") {
        king[1] = (char) (king[1] - 1);
    } else if (inst == "T") {
        king[1] = (char) (king[1] + 1);
    } else if (inst == "RT") {
        king[0] = (char) (king[0] + 1);
        king[1] = (char) (king[1] + 1);
    } else if (inst == "LT") {
        king[0] = (char) (king[0] - 1);
        king[1] = (char) (king[1] + 1);
    } else if (inst == "RB") {
        king[0] = (char) (king[0] + 1);
        king[1] = (char) (king[1] - 1);
    } else if (inst == "LB") {
        king[0] = (char) (king[0] - 1);
        king[1] = (char) (king[1] - 1);
    }

    if (king == stone) {
        stone[0] = (char) (stone[0] + king[0] - temp_king[0]);
        stone[1] = (char) (stone[1] + king[1] - temp_king[1]);
    }

    if (king[0] < 'A' || king[0] > 'H' || king[1] > '8' || king[1] < '1' || stone[0] < 'A' || stone[0] > 'H' ||
        stone[1] > '8' || stone[1] < '1') {
        king = temp_king;
        stone = temp_stone;
    }
}

int main() {
    string king, stone;
    int n;
    cin >> king >> stone >> n;

    while (n--) {
        string inst;
        cin >> inst;

        move(king, stone, inst);
    }
    cout << king << "\n" << stone;
    return 0;
}