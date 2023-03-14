#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    vector<char> v(N);
    fill(v.begin(), v.end(), '?'); // vector를 전부 ?으로 저장
    int k = 0;
    for (int i = 0; i < K; i++)
    {
        int temp;
        char c;
        cin >> temp >> c;

        temp %= N;
        if (k - temp < 0)
        {
            k = (k - temp) + N;
        }
        else
        {
            k -= temp;
        }

        if (v[k] != '?' && v[k] != c)
        {
            cout << "!\n";
            return 0;
        }
        else
        {
            v[k] = c;
        }
    }

    for (int i = 0; i < N; i++)
        for (int j = i + 1; j < N; j++)
        {
            if (v[i] != '?' && v[i] == v[j])
            {
                cout << "!\n";
                return 0;
            }
        }

    for (int i = 0; i < N; i++)
    {
        cout << v[(i + k) % N];
    }
    cout << "\n";

    return 0;
}