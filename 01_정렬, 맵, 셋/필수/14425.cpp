#include <iostream>
#include <string>
#include <set>

using namespace std;

int a, b;
set<string> S;

int main()
{
    string s;
    int i, cnt = 0;

    cin >> a >> b;
    for (i = 0; i < a; i++)
    {
        cin >> s;
        S.insert(s);
    }
    for (i = 0; i < b; i++)
    {
        cin >> s;
        if (S.find(s) != S.end())
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}
