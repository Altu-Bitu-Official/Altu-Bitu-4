#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

typedef pair<string, string> ci;
typedef pair<int, int> pos;

const pos FAIL = {-1, -1};

pos afterMove(pos p, string m)
{
    if (m == "R" && p.first != 7)
    {
        p.first++;
    }
    else if (m == "L" && p.first != 0)
    {
        p.first--;
    }
    else if (m == "B" && p.second != 0)
    {
        p.second--;
    }
    else if (m == "T" && p.second != 7)
    {
        p.second++;
    }
    else if (m == "RT" && p.first != 7 && p.second != 7)
    {
        p.first++;
        p.second++;
    }
    else if (m == "LT" && p.first != 0 && p.second != 7)
    {
        p.first--;
        p.second++;
    }
    else if (m == "RB" && p.first != 7 && p.second != 0)
    {
        p.first++;
        p.second--;
    }
    else if (m == "LB" && p.first != 0 && p.second != 0)
    {
        p.first--;
        p.second--;
    }
    else // 말이 체스판 밖으로 나갈 경우
    {
        p.first = -1;
        p.second = -1;
    }
    return p;
}

ci getFinal(queue<string> &moves, string king, string stone)
{
    pos k = {king[0] - 'A', king[1] - '1'};
    pos s = {stone[0] - 'A', stone[1] - '1'};
    ci result = {"A1", "A1"};

    while (!moves.empty())
    {
        string m = moves.front();
        moves.pop();
        if (afterMove(k, m) == FAIL || afterMove(k, m) == s && afterMove(s, m) == FAIL)
        {
            continue;
        }
        k = afterMove(k, m);
        if (k == s)
        {
            s = afterMove(s, m);
        }
    }

    result.first[0] += k.first;   // 킹의 열
    result.first[1] += k.second;  // z킹의 행
    result.second[0] += s.first;  // 돌의 열
    result.second[1] += s.second; // 돌의 행

    return result;
}

int main()
{
    string king, stone, move;
    int n;
    queue<string> moves;

    cin >> king >> stone >> n;

    while (n--)
    {
        cin >> move;
        moves.push(move);
    }

    ci result = getFinal(moves, king, stone);

    cout << result.first << '\n'
         << result.second;
}