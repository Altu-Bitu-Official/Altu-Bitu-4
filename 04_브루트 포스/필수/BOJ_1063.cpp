#include <iostream>
#include <vector>
#include <string>

using namespace std;

int x[8] = {1, -1, 0, 0, 1, -1, 1, -1}; // 오 왼 아래 위 오위 왼위 오바 왼바
int y[8] = {0, 0, -1, 1, 1, 1, -1, -1};

int index(string location)
{
    if (location == "R")
    {
        return 0;
    }
    else if (location == "L")
    {
        return 1;
    }
    else if (location == "B")
    {
        return 2;
    }
    else if (location == "T")
    {
        return 3;
    }
    else if (location == "RT")
    {
        return 4;
    }
    else if (location == "LT")
    {
        return 5;
    }
    else if (location == "RB")
    {
        return 6;
    }
    else if (location == "LB")
    {
        return 7;
    }
}

int kingIsStone(vector<int> &king, vector<int> &dol, vector<int> &idx, int i)
{
    if (king[0] + x[idx[i]] == dol[0] && king[1] + y[idx[i]] == dol[1])
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int include(vector<int> &a, vector<int> &idx, int i)
{
    if ((a[0] + x[idx[i]]) < 1 || (a[0] + x[idx[i]]) > 8 || (a[1] + y[idx[i]]) < 1 || (a[1] + y[idx[i]] > 8))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void result(vector<int> &king, vector<int> &dol, vector<int> &idx, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (kingIsStone(king, dol, idx, i)) // king dol idx 0
        {
            if (include(dol, idx, i)) // dol idx 0
            {
                king[0] += x[idx[i]];
                dol[0] += x[idx[i]];
                king[1] += x[idx[i]];
                dol[1] += x[idx[i]];
            }
            else
            {
                continue;
            }
        }
        else
        {
            if (include(king, idx, i))
            {
                king[0] += x[idx[i]];
                king[1] += x[idx[i]];
            }
            else
            {
                continue;
            }
        }
    }
}

int main()
{
    string k, d;
    int n;
    cin >> k >> d >> n;

    vector<int> king(2);
    vector<int> dol(2);

    king[0] = k[0] - 'A';
    king[1] = k[1] - '0';
    dol[0] = d[0] - 'A';
    dol[1] = d[1] - '0';

    string location;
    vector<int> idx(n);
    int i;
    while (n--)
    {
        i = 0;
        cin >> location;
        idx[i++] = index(location); 
    }

    result(king, dol, idx, n);

    cout << char(king[0] + 'A') << king[1] << "\n";
    cout << char(dol[0] + 'A') << dol[1] << "\n";
    return 0;
}