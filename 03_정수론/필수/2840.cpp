#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

void checkWheel(int &k, const int n, int& s, vector<char> &wheel, int alphabet[])
{
    char c;
    int before = 0; // 직전 s
    while (k--)
    {
        cin >> s >> c; // 글자가 몇 번 바뀌었는지를 나타내는 S와 회전을 멈추었을 때 가리키던 글자 입력

        s %= n; // 바퀴가 여러번 도는 경우 방지
        if (before - s < 0)
        {
            s = before - s + n;
        }
        else
        {
            s = before - s;
        }
        before = s;

        //바퀴가 비어있거나 해당 문자가 들어가 있다면
        if(wheel[s] == '?' || wheel[s] == c){    
            wheel[s] = c;
        }
        //존재하지 않는 바퀴
        else{ 
            cout << "!";
            exit(0);
        }
    }
}

void checkDuplication(vector<char> &wheel)
{
    for(int i=0; i<wheel.size(); i++){
        for(int j=i+1; j<wheel.size(); j++){
            //?를 제외하고 중복된 문자가 있을 시 종료
            if(wheel[i] != '?' && wheel[j] != '?' && wheel[i] == wheel[j]){
                cout << "!";
                exit(0);
            }
        }
    }
}

int main()
{
    int n, k;
    int s;

    vector<char> wheel;
    int alphabet[30] = {0, };

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        wheel.push_back('?'); // 바퀴를 ?로 채우기
    }
    //바퀴 채우기
    checkWheel(k, n, s, wheel, alphabet);
    //중복 알파벳 검사
    checkDuplication(wheel);
    // 출력
    for (int i = 0; i < n; i++)
    {
        cout << wheel[s];
        s++;
        if (s >= n)
        {
            s = 0;
        }
    }
}