#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, k;
int index = 0; //화살표가 가리키는 index
bool flag = true; //해당 행운의 바퀴가 있는지 확인

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


void wheel(int s, char c, vector<char> &v) {
    //시계방향으로 바퀴를 회전 > 인덱스가 감소하는 것처럼 보임
    //index에 글자 저장
    if (index - s < 0) {//index - s 음수인 경우
        index = (index - s) + n;
    }
    else {//아닌 경우
        index -= s;
    }
    //<주의 사항> 1.
    //한 인덱스에 다른 알파벳 중복 저장하려 할 때
    if (v[index] != '?' && v[index] != c) {
        flag = false;
    }
    else {
        v[index] = c;
        //중복 저장이 아니라면 원판에 기록
    }
}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k; //입력

    vector<char> v(n, '?'); //벡터 v ?로 초기화

    for (int i = 0; i < k; i++) {
        if (!flag) break;
        int s; 
        char c;

        cin >> s >> c;
        s %= n;
        //각 줄의 글자가 바뀐 횟수 s와 그때 가리킨 글자 c
        wheel(s, c, v);
    }

    //<주의 사항> 2.
    //룰렛에 중복되는 문자가 있는 경우
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (v[i] != '?' && v[i] == v[j]) {
                cout << "!\n";
                return 0;
            }

    //출력
    //<주의 사항>에 해당하지 않는 경우
    if (!flag) {
        cout << "!\n"; //해당하는 행운의 바퀴 없음 => "!" 출력
        return 0;
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << v[(i + index) % n];
        }
        cout << "\n";
    }
    return 0;

}