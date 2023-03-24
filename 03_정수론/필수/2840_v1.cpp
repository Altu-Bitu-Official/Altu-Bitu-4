#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> ci;
const int ALPHA = 26;

/*
    [2840 행운의 바퀴 ver1]
    - 문제에서 주어진대로 화살표를 고정시키고, 바퀴를 시계방향으로 돌려서 문제를 푼다.
    - 배열을 ?로 초기화 해주고, 입력한대로 처리한다
    - 바퀴를 배열로 보고 시계방향으로 바퀴를 회전시키면, 화살표가 가리키고 있는 배열의 원소는 인덱스가 감소하는 것처럼
   보인다.
    <주의 사항>
    1. ?이 아닌 문자가 저장되어있는데, 다른 문자를 저장하려는 경우
    2. 룰렛에 중복되는 문자가 있는 경우
    ** 바퀴를 돌리는 횟수가 매우 클 수도 있다. 이 부분을 유의하여 인덱스를 처리하자!
    ex) n=3 인데, 바퀴를 10번 돌릴수도 있다.
*/

// 특정 화살표에서 시작한 행운의 바퀴 리턴
string arrowStartWheel(int index, int n, vector<char> &wheel) {
    string ans = "";

    for (int i = 0; i < n; i++) {
        ans += wheel[(i + index) % n];
    }

    return ans;
}

string makeWheel(int n, vector<ci> &record) {
    vector<char> wheel(n, '?');              //?로 초기화
    vector<bool> is_available(ALPHA, false); // 알파벳 중복 체크

    int index = 0; // 화살표가 가리키는 인덱스

    for (int i = 0; i < record.size(); i++) {
        int rot = record[i].first;
        int ch = record[i].second;

        index = (index - rot + 100 * n) % n;

        if (wheel[index] == ch) {
            continue;
        }

        // 주의사항 체크
        // 원판의 해당 위치에 다른 문자가 저장되어있거나, 이미 다른 곳에 문자가 사용된 경우
        if (wheel[index] != '?' || is_available[ch - 'A']) {
            return "!";
        }

        wheel[index] = ch;             // 원판에 기록
        is_available[ch - 'A'] = true; // 알파벳 사용을 표시
    }

    return arrowStartWheel(index, n, wheel);
}

int main() {
    // 입력
    int n, k;
    cin >> n >> k;

    vector<ci> record(k, {0, 0}); // 바퀴 회전 기록
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >> record[i].second;
    }

    // 출력
    cout << makeWheel(n, record);
    
    return 0;
}