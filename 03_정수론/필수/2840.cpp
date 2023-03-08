#include <iostream>
#include <vector>

using namespace std;

string arrowStartWheel(int index, int n, vector<char> &wheel) //& 기호를 활용하면 값을 직접 바꿀 수 있음, 메모리 덜 차지함
{
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        ans += wheel[(i + index) % n]; // 마지막의 위치부터 시작하기 위함(나머지:0~n-1)
    }
    return ans;
}

typedef pair<int, char> ci;
// int, char를 모두 받아주기 위해 typdef 활용, 새로운 type ci 정의
string makeWheel(int n, vector<ci> &record) //& 기호를 활용하면 값을 직접 바꿀 수 있음, 메모리 덜 차지함
{
    vector<char> wheel(n, '?');           // 바퀴에 들어있는 문자 vector
    vector<bool> is_available(26, false); // 해당 문자가 쓰였는지 확인하기 위함
    int index = 0;
    for (int i = 0; i < record.size(); i++) // record.size()=k만큼 반복
    {
        int rot = record[i].first;  // 지나친 문자의 수
        char ch = record[i].second; // 멈췄을 때 가리키는 문자

        index = (index - rot + 100 * n) % n; // 읽을 때와 문자가 지나치는 방향이 반대이므로 rot을 빼 줌
                                             // rot이 큰 수일 경우를 대비해 n에 적당히 큰 수를 곱해줌
        if (wheel[index] == ch)
        {
            // 비어있지 않지만 값이 같은 경우, 다음 for문으로
            continue;
        }
        if (wheel[index] != '?' || is_available[ch - 'A'])
        {
            // 비어있지 않고, 사용한 경우, !
            return "!";
        }

        wheel[index] = ch;             // 비어있다면 값을 넣어줌
        is_available[ch - 'A'] = true; // 값을 넣었음을 의미
    }
    return arrowStartWheel(index, n, wheel); // 최종 index, 바퀴의 칸 수, wheel vector
}

int main()
{ // 입출력 시간 줄이기 위한 식
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<ci> record(k, {0, 0}); // 위에서 정의한 ci type, k번 값을 받아올 것

    for (int i = 0; i < k; i++) // k번 반복
    {
        cin >> record[i].first >> record[i].second;
        // first: 문자를 지나친 횟수, second: 멈췄을 때 가리키는 문자
    }

    cout << makeWheel(n, record); // makeWheel에 바퀴의 칸 수, 입력값을 인자로 줌
    return 0;
}