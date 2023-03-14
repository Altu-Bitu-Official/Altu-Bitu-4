#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> ci; // 바퀴 이동수, 문자를 저장함
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
string arrowStartWheel(int index, int n, vector<char>& wheel) {
    string ans = "";

    for (int i = 0; i < n; i++) {
        ans += wheel[(i + index) % n]; // 인덱스부터 시작해서 시계방향으로 프린트한다.
    }

    return ans;
}

string makeWheel(int n, vector<ci>& record) {
    vector<char> wheel(n, '?');              //?로 초기화
    vector<bool> is_available(ALPHA, false); // 알파벳 중복 체크 - 바퀴에 같은 글자는 두 번 이상 등장하지 않기 때문

    int index = 0; // 화살표가 가리키는 인덱스

    for (int i = 0; i < record.size(); i++) {
        // 저장된 값 하나씩 빼내기
        int rot = record[i].first;
        int ch = record[i].second;

        // 바퀴가 돌아가면서 이전의 인덱스를 가리키게 된다.
        // 인덱스가 음수가 되지 않도록 100 * 칸의 수를 더해주고, 결과값을 다시 칸의 수로 나눠준다.
        index = (index - rot + 100 * n) % n;

        // 해당 인덱스의 문자가 이미 알려져있고, 모순이 없으면 반복문을 그대로 통과
        if (wheel[index] == ch) {
            continue;
        }

        // 주의사항 체크
        // 원판의 해당 위치에 다른 문자가 저장되어있거나, 이미 다른 곳에 문자가 사용된 경우
        // 모순이 발생했으므로 바로 !를 리턴한다.
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

    vector<ci> record(k, { 0, 0 }); // 바퀴 회전 기록
    for (int i = 0; i < k; i++) {
        cin >> record[i].first >> record[i].second; // first, second로 접근가능하다
    }

    // 출력
    cout << makeWheel(n, record);

    return 0;
}