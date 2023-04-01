#include <iostream>
#include <vector>
#include <numeric>
#include <string>

const int ALPHA = 26;

using namespace std;

bool check(vector<int> &alpha_diff)
{
    int zero = 0;
    int pos1 = 0;
    int neg1 = 0;
    for (int d : alpha_diff)
    {
        if (d == 0)
        {
            zero++;
        }

        else if (d == 1)
        {
            pos1++;
        }

        else if (d == -1)
        {
            neg1++;
        }
    }
    // 구성 같음, 문자 하나 더해야함, 문자 하나 빼야함, 문자 하나 바꿔야함.
    if (zero == ALPHA || zero == ALPHA - 1 && pos1 == 1 || zero == ALPHA - 1 && neg1 == 1 || zero == ALPHA - 2 && pos1 == 1 && neg1 == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    vector<int> alpha_freq(ALPHA);
    int n, cnt = 0;
    string s, w;
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        alpha_freq[s[i] - 'A']++;
    }

    while (--n)
    {
        cin >> w;
        vector<int> alpha_diff = alpha_freq;
        for (int i = 0; i < w.size(); i++)
        {
            alpha_diff[w[i] - 'A']--;
        }
        if (check(alpha_diff))
        {
            cnt++;
        }
    }

    cout << cnt;
}