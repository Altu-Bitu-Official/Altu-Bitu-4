#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void)

{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k; // 바퀴 개수, 총 회전 개수

    cin >> n >> k;

    vector<char> arr(n, '?');

    int idx = 0;

    for (int i = 0; i < k; i++)

    {
        int a;  // 글자 바뀐 개수
        char c; // 문자

        cin >> a >> c;

        a %= n;

        if (idx - a >= 0)
        {
            idx -= a;
        }

        else
        {
            idx = (idx - a) + n;
        }

        if (arr[idx] != '?' && arr[idx] != c) // 이전에 지금과 같은 인덱스가 존재할때, 이전과 지금의 인덱스 배열값이 다를 경우
        {
            cout << "!";
            return 0;
        }

        else
        {
            arr[idx] = c;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] != '?' && arr[i] == arr[j]) // 서로 다른 인덱스에서 배열 값이 값을 경우 바퀴는 중복되지 않음

            {
                cout << "!";
                return 0;
            }
        }
    }

    for (int i = idx; i < n; i++)
    {
        cout << arr[i];
    }

    for (int i = 0; i < idx; i++)
    {
        cout << arr[i];
    }

    cout << "\n";
    return 0;
}