#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> alphabet(26, 0);
void alphabetArr(string input)
{
    for (int i = 0; i < input.size(); i++)
    {
        alphabet[input[i] - 'A']++;
    }
}

bool check(vector<int> &alphabet, string str)
{
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] == 0 || alphabet[i] % 2 == 0)
        {
            cnt++;
        }
    }
    if (cnt == 26)
    {
        return true;
    }
    else
    {
        return false;
    }
}
string solution1(string str, vector<int> &alphabet)
{
    int j = 0;
    string ans = str;
    for (int i = 0; i < 26; i++)
    {

        while (alphabet[i] >= 2)
        {
            str[j++] = 'A' + i;
            alphabet[i] -= 2;
        }
    }
    for (int i = 0; i < j; i++)
    {
        ans[i] = str[i];
    }
    int t = j - 1;
    for (int k = j; k < str.size(); k++)
    {
        ans[k] = str[t--];
    }
    return ans;
}

string solution2(string str, vector<int> &alphabet, int j)
{
    int s = 0;
    string ans = str;
    int center = (str.size() - 1) / 2;

    for (int i = 0; i < 26; i++)
    {
        while (alphabet[i] >= 2)
        {
            str[s++] = 'A' + i;
            alphabet[i] -= 2;
        }
    }

    for (int i = 0; i < center; i++)
    {
        ans[i] = str[i];
    }
    ans[center] = 'A' + j;

    int t = s - 1;
    for (int k = center + 1; k < str.size(); k++)
    {
        ans[k] = str[t--];
    }
    return ans;
}
int main()
{
    string str;
    int j, cnt = 0;
    cin >> str;
    alphabetArr(str);
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] % 2 == 1)
        {
            j = i;
            cnt++;
        }
    }

    if (check(alphabet, str) && str.size() % 2 == 0) // 서로다른문자가 각각 모두 짝수
    {
        cout << solution1(str, alphabet);
    }
    else if (alphabet[j] % 2 == 1 && cnt == 1)
    {
        cout << solution2(str, alphabet, j);
    }
    else
    {
        cout << "I'm Sorry Hansoo";
    }

    return 0;
}