#include <iostream>
#include <string>

using namespace std;

bool isApoc(int i)
{
    string idx = to_string(i);
    string apoc = "666";
    if (idx.find(apoc) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int getApoc(int n)
{
    int i = 0;
    int cnt = 0;
    while (true)
    {
        if (isApoc(i))
        {
            cnt++;
        }
        if (cnt == n)
        {
            return i;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    cout << getApoc(n);
}