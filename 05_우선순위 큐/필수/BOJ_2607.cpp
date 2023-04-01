#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> alphabetArr(string input)
{
    vector<int> alphabet(26, 0);
    for (int i = 0; i < input.size(); i++)
    {
        alphabet[input[i] - 'A']++;
    }
    return alphabet;
}

int checkArr(string input1, string input2)
{
    int diff = 0;
    vector<int> origin(26, 0);
    vector<int> cmp(26, 0);
    origin = alphabetArr(input1);
    cmp = alphabetArr(input2);
    for (int i = 0; i < 26; i++)
    {
        diff += abs(origin[i] - cmp[i]);
    }

    if (diff <= 2 && abs(int(input1.size() - input2.size())) <= 1)
    {
        return 1;
    }

    return 0;
}
int main()
{
    int n, cnt = 0;
    cin >> n;
    string input1;
    cin >> input1;
    for (int i = 0; i < n - 1; i++)
    {
        vector<string> str(n - 1);
        cin >> str[i];

        if (checkArr(input1, str[i]))
        {
            cnt++;
        }
    }
    cout << cnt;

    return 0;
}