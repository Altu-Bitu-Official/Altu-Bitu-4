#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef pair <char,char> cc; //pair를 이용해서 cc를 선언

cc move(string input, char x, char y){ //이동함수 move, x는 열, y는 행
    for (int i = 0; i < input.size(); i++) { //input.size()=이동하는 횟수만큼 반복
        char how = input[i]; //how는 문자형으로 선언, 움직임에 해당하는 알파벳을 하나씩 배열에 넣음
        if (how == 'R') { // how 변수가 R이라면
            x++; // 오른쪽으로 한 칸 이동
        }
        else if (how == 'L') { // how 변수가 L이라면
            x--; // 왼쪽으로 한 칸 이동
        }
        else if (how == 'B') { // how 변수가 B이라면
            y--; // 아래쪽으로 한 칸 이동
        }
        else {// how 변수가 T이라면
            y++; // 위쪽으로 한 칸 이동

        }
    }
    return { x, y }; //모든 작업을 하고 나면 최종 위치인 x와 y를 반환

}

bool checkRange(cc position) {//범위 체크 하는 함수

    // 열이 A부터 H까지, 행이 1부터 8까지에 속하지 않으면 거짓
    if (position.first < 'A' || position.first > 'H'
        || position.second < '1' || position.second > '8') {
        return false;
    }
    // 범위 내에 속하면 참을 리턴함
    return true;
}

bool isSame(cc k, cc s) { //king과 돌의 위치가 같은지를 확인하는 함수
    // 열은 열끼리, 행은 행끼리 같은지 비교
    return (k.first == s.first && k.second == s.second);

}

/*
* HINT : 문자형 변수의 연산은 비교적 자유로워요!
 * 또 킹과 돌의 움직임이 모두 판 안에서 이뤄질 때만 다음으로 움직일 수 있는 점을 신경써주세요!
* 1. king 이동 (move)
* 2. king과 stone의 위치 동일 -> stone 이동 (move)
* 3. king과 stone의 위치 점검 (checkRange
*/

int main() { //main함수

    cc k, s;//king, stone
    int n; //움직임의 개수
    string input; //input은 움직임 하나하나

    //입력 first는 열, second는 행, n은 움직임의 개수
    cin >> k.first >> k.second >> s.first >> s.second >> n;

    //연산
    while (n--) { //n번만큼 반복문을 돈다.
        cin >> input; //움직임을 입력받는다.

        cc next_k, next_s;//이동 후 king과 돌의 위치를 저장할 변수

        //king 이동
        next_k = move(input, k.first, k.second);

        //stone 이동
        if (isSame(next_k,s)) { //king의 다음 위치와 stone의 현재위치가 같으면
            next_s = move(input, s.first, s.second); //돌의 다음위치는 move한 위치
        }
        else { // 둘의 위치가 겹치지 않는다면
            next_s = s; //돌의 위치는 그래도 유지
        }

        //범위 체크
        if (checkRange(next_k) && checkRange(next_s)){//이동한 king과 돌이 범위 내에 있으면
            k = next_k; //king의 새로운 위치가 갱신된다.
            s = next_s; //돌의 새로운 위치가 갱신된다.
        }

    }

    //king의 마지막 위치와 돌의 마지막 위치를 출력한다.
    cout << k.first << k.second <<'\n'<< s.first << s.second ;
    return 0;
}