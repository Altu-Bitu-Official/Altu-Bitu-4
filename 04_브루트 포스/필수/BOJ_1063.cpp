#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef pair<char, char> cc; // 문자 쌍 typedef cc선언

cc move(string input, char x, char y)
{ // 입력방향, 현재위치<x,y>를 매개변수로 받아 이동한 위치 <x,y>반환
    for (int i = 0; i < input.size(); i++)
    {                        // 입력받은 문자열 확인
        char how = input[i]; // R,L,T,B를 받아 x,y 이동
        if (how == 'R')
        { // right인 경우 x++
            x++;
        }
        else if (how == 'L')
        { // left인 경우 x --
            x--;
        }
        else if (how == 'B')
        { // bottom인 경우 y--
            y--;
        }
        else
        { // top인 경우 y++
            y++;
        }
    }

    return {x, y}; // 새 위치 반환
}

bool checkRange(cc position) // 범위 체크 하는 함수
{

    if (position.first < 'A' || position.first > 'H' || position.second < '1' || position.second > '8') // 범위를 넘어가는 경우
    {
        return false; // 거짓반환
    }

    return true;
}

bool isSame(cc k, cc s)
{ // king과 stone의 위치가 동일한 경우 참 반환
    return (k.first == s.first && k.second == s.second);
}

int main()
{

    cc k, s;      // king, stone
    int n;        // 입력할 횟수
    string input; // 이동방향

    // 입력
    cin >> k.first >> k.second >> s.first >> s.second >> n;

    while (n--) // n번 연산
    {
        cin >> input;

        cc next_k, next_s; // 이동 후 위치 저장할 변수

        // king 이동
        next_k = move(input, k.first, k.second);

        // stone 이동
        if (isSame(next_k, s)) // king과 stone의 위치가 동일한 경우 stone의 위치를 변환
        {
            next_s = move(input, s.first, s.second); // 새로운 stone의 위치를 next_S에 저장
        }
        else
        {
            next_s = s; // 동일하지 않으면 상관없으니 원래 s값을 저장
        }

        // 범위 체크
        if (checkRange(next_k) && checkRange(next_s))
        { // 이동한 king과 stone가 유효 범위면 최종적으로 이동
            k = next_k;
            s = next_s;
        }
    }

    // 출력
    cout << k.first << k.second << '\n'
         << s.first << s.second;
    return 0;
}