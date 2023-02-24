#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<string> s;
    int n;
    int m;
    string str1;
    string str2;
    int cnt = 0;

    cin >> n >> m;

    //입력
    while (n--)
    {
        cin >> str1;
        s.insert(str1);
    }

    //M의 element가 N 안에 존재하면 count
    while (m--)
    {
        cin >> str2;
        if (s.find(str2) != s.end())
        {
            cnt++;
        }
    }

    cout << cnt;
}