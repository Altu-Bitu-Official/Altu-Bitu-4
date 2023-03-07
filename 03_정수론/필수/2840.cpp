#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string answer(int i, vector<char> &wheel)
{
    string result = "";
    int n = wheel.size();

    for (int j = 0; j < n; j++)
    {
        if (i - j < 0) // 인덱스가 음수 되는 것 방지
        {
            result += wheel[i - j + n];
        }
        else
        {
            result += wheel[i - j];
        }
    }

    return result;
}

bool isValid(int i, char ch, vector<char> &wheel)
{
    auto it = find(wheel.begin(), wheel.end(), ch);

    // 조건1 : 알파벳이 이미 존재할경우, 같은 자리여야한다
    if (it != wheel.end() && it != wheel.begin() + i)
    {
        return false;
    }

    // 조건2 : 자리에 다른 알파벳이 없어야 한다
    if (wheel[i] == '?' || wheel[i] == ch)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n, k, s; // 바퀴 칸 수, 돌리는 횟수, 화살표 가리키는 글자 변화 수
    char ch;     // 멈췄을때의 글자

    cin >> n >> k;
    vector<char> wheel(n, '?');

    int i = 0; // 현재 화살표 인덱스

    while (k--) // 시계 반대방향으로 배열을 채워나감
    {
        cin >> s >> ch;
        i = (i + s) % n;

        if (isValid(i, ch, wheel))
        {
            wheel[i] = ch;
        }
        else
        {
            cout << '!';
            return 0;
        }
    }

    // 출력 시 마지막 인덱스에서부터 시계방향으로, 배열 꺼꾸로 올라감
    cout << answer(i, wheel);
}