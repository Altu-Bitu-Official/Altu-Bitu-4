#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<string> S;
    int N;
    int M;
    string str1;
    string str2;
    int cnt = 0;

    cin >> N >> M;

    while (N--)
    {
        cin >> str1;
        S.insert(str1);
    }

    while (M--)
    {
        cin >> str2;
        if (S.find(str2) != S.end())
            cnt++;
    }

    cout << cnt;
}