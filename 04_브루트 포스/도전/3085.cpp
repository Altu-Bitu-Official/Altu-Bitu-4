#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getCandy(vector<vector<char>> &b)
{
    // row에서 찾기
    int cnt;
    char prev;
    int result = 0;
    for (int i = 0; i < b.size(); i++)
    {
        cnt = 1;
        prev = b[i][0];
        for (int j = 1; j < b[i].size(); j++)
        {
            if (prev == b[i][j])
            {
                cnt++;
            }
            else
            {
                result = max(result, cnt);
                cnt = 1;
            }
            prev = b[i][j];
        }
        result = max(result, cnt);
    }

    // col에서 찾기

    for (int i = 0; i < b.size(); i++)
    {
        cnt = 1;
        prev = b[0][i];
        for (int j = 1; j < b[i].size(); j++)
        {
            if (prev == b[j][i])
            {
                cnt++;
            }
            else
            {
                result = max(result, cnt);
                cnt = 1;
            }
            prev = b[j][i];
        }
        result = max(result, cnt);
    }
    return result;
}

int getMostCandy(vector<vector<char>> &board)
{
    int candy, result = 0;
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 1; j < board[i].size(); j++)
        {
            if (board[i][j - 1] != board[i][j])
            {
                vector<vector<char>> b_row = board;
                swap(b_row[i][j - 1], b_row[i][j]);
                candy = getCandy(b_row);
                result = max(result, candy);
            }

            if (board[j - 1][i] != board[j][i])
            {
                vector<vector<char>> b_col = board;
                swap(b_col[j - 1][i], b_col[j][i]);
                candy = getCandy(b_col);
                result = max(result, candy);
            }
        }
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    string s;
    cin >> n;
    vector<vector<char>> board(n, vector<char>(n, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            board[i][j] = s[j];
        }
    }

    cout << getMostCandy(board);
}