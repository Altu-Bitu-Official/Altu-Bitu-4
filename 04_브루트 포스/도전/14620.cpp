#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int getTotal(vector<vector<int>> cost, int i, int j, int k, int n)
{

    int result = 0;
    int dx[5] = {0, 1, 0, -1, 0};
    int dy[5] = {0, 0, 1, 0, -1};
    pair<int, int> fi = {i / n + 1, i % n + 1};
    pair<int, int> fj = {j / n + 1, j % n + 1};
    pair<int, int> fk = {k / n + 1, k % n + 1};
    if (abs(fi.first - fj.first) + abs(fi.second - fj.second) < 3 || abs(fk.first - fj.first) + abs(fk.second - fj.second) < 3 || abs(fk.first - fi.first) + abs(fk.second - fi.second) < 3)
    {
        return 3000;
    }
    else
    {
        for (int l = 0; l < 5; l++)
        {
            result += cost[fi.first + dx[l]][fi.second + dy[l]];
            result += cost[fj.first + dx[l]][fj.second + dy[l]];
            result += cost[fk.first + dx[l]][fk.second + dy[l]];
        }
        return result;
    }
}

int getMinTotal(vector<vector<int>> &cost, int n)
{

    int result = 3000;
    for (int i = 0; i < n * n; i++)
    {
        for (int j = i + 1; j < n * n; j++)
        {
            for (int k = j + 1; k < n * n; k++)
            {
                result = min(result, getTotal(cost, i, j, k, n));
            }
        }
    }
    return result;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> cost(n + 2, vector<int>(n + 2, 1000));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> cost[i][j];
        }
    }

    cout << getMinTotal(cost, n);
}