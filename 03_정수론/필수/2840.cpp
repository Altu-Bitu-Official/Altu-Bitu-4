#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> ci;//int, char 넣을 수 있는 걸 ci로 정의
const int ALPHA = 26;//알파벳갯수

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
string arrowStartWheel(int index, int n, vector<char>& wheel) {//n: 바퀴 돌린 숫자, index: 여기서시작(마지막 멈춘곳부터), wheel: 바퀴 업데이트(주소받음)
    string ans = "";//바퀴[] 를 ans에 리턴

    for (int i = 0; i < n; i++) {// 바퀴칸수만큼
        ans += wheel[(i + index) % n];//인덱스에있는거 ans에 string더함
    }

    return ans;//답안리턴
}

string makeWheel(int n, vector<ci>& record) {
    vector<char> wheel(n, '?');              //?로 초기화(n: 바퀴칸수)
    vector<bool> is_available(ALPHA, false); // 알파벳 중복 체크//26개, false로 초기화

    int index = 0; // 화살표가 가리키는 인덱스

    for (int i = 0; i < record.size(); i++) {//주어진 단서만큼 돌린다(남긴 종이)
        int rot = record[i].first;//첫번째: 알파벳바뀐횟수
        int ch = record[i].second;//두번째: 멈춘알파벳

        index = (index - rot + 100 * n) % n;//나머지: 0~n-1까지니까 이러면 회전하는것처럼 인덱스 만들 수 있음

        if (wheel[index] == ch) {//원판의 해당 위치에 알파벳이 있는데, 그게 자기 자신과 동일하면 OK
            continue;//다시위로
        }

        // 주의사항 체크
        // 원판의 해당 위치에 알파벳이 있는데, 그게 다른 글자이면 원판 만들기 불가능
        // 원판의 해당 위치에 다른 문자가 저장되어있거나, 이미 다른 곳에 문자가 사용된 경우
        if (wheel[index] != '?' || is_available[ch - 'A']) {//위에 if문 안 걸리고 내려온 상태에서 ?아니거나==이미 다른 문자 써 져 있음|| 이미 쓴 문자일경우
            return "!";//행운의바퀴 못 만듦
        }

        wheel[index] = ch;             // 원판에 기록
        is_available[ch - 'A'] = true; // 알파벳 사용을 표시
    }

    return arrowStartWheel(index, n, wheel);//출력문 리턴하는 걸 리턴
}

int main() {
    // 입력
    int n, k;//n: 바퀴 칸 수, k: 돌리는 횟수
    cin >> n >> k;//입력받음

    vector<ci> record(k, { 0, 0 }); // 바퀴 회전 기록
    for (int i = 0; i < k; i++) {//s와 글자
        cin >> record[i].first >> record[i].second;//반복해서 입력받음(k까지)
    }

    
    cout << makeWheel(n, record);// 답안 출력

    return 0;
}