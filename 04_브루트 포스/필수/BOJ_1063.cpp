#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef pair<char, char> cc;

cc location(string input, char x, char y) //입력받은 위치 열x 행y
{
    for (int i = 0; i < input.size(); i++) //  RT RB 와 같이 크기가 2개일 수 있다
    {
        char how = input[i];
        if (how == 'R')
        {
            x++; //원래 위치에서 증가시킴
        }
        else if (how == 'L')
        {
            x--;
        }
        else if (how == 'B')
        {
            y--;
        }
        else
        {
            y++;
        }
    }
    return {x, y};
}

// 이동된 킹의 위치가 원래의 스톤과 일치할때
bool sameStone(cc new_k, cc s)
{

    return (new_k.first == s.first && new_k.second == s.second);
}
/* 질문
아래 sameStone 함수를 사용하면 입력값을 넣었을때 출력값이 제대로 도출되지 않습니다
혹시 그 이유를 알 수 있을까요?
*/
/*
bool sameStone(cc new_k, cc s)
{

    if (new_k.first == s.first && new_k.second == s.second)
    {
        return true;
    }
}
*/
bool check(cc pos) //현재 위치가 체스판 범위를 넘어서는지 확인하는 함수
{
    if (pos.first < 'A' || pos.second > '8' || pos.first > 'H' || pos.second < '1')
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    cc k, s; //입력하는 킹과 스톤
    int n;//개수
    string input; // 개수만큼의 위치
    // 입력
    cin >> k.first >> k.second >> s.first >> s.second >> n;
    // 계산
    while (n--)
    {
        cin >> input;
        cc new_k, new_s;                            // 이동된 k , s
        new_k = location(input, k.first, k.second); // 이동된 k.  킹을 업데이트 시킨다

        if (sameStone(new_k, s)) //만약 업데이트된 킹이 스톤과 만나면
        {
            new_s = location(input, s.first, s.second); // 스톤을 업데이트시킨다
        }
        else //아니라면
        {
            new_s = s; // 스톤은 그대로
        }

        if (check(new_k) && check(new_s)) // 킹과 스톤이 문제에서 정해진 범위에 놓여있는지 확인 후
        {
            k = new_k; //입력받은 킹값을 new_k로 업데이트
            s = new_s; //입력받은 스톤값을 new_s로 업데이트
        }
    }

    // 출력
    cout << k.first << k.second << "\n"
         << s.first << s.second;
    return 0;
}