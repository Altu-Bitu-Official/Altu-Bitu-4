#include <iostream>
#include <vector>
const int ALPHA = 26;

using namespace std;

string getPalindrome(vector<int> alpha)
{
    int cnt = 0;
    string mid = "";
    for (int i = 0; i < ALPHA; i++)
    {
        // 홀수를 '중간값'으로저장함
        if (alpha[i] % 2 == 1)
        {
            alpha[i]--;
            cnt++;
            mid += 'A' + i;
        }
        if (cnt > 1)
        {
            // 홀수가 단 한개 이하가 아니라면, "미안 한수!"
            return "I'm Sorry Hansoo";
        }
    }

    string palindrome;

    // 앞부분
    for (int i = 0; i < ALPHA; i++)
    {
        for (int j = 0; j < alpha[i] / 2; j++)
        {
            palindrome += 'A' + i;
        }
    }

    // 중간
    palindrome += mid;

    // 뒷부분
    for (int i = ALPHA - 1; i >= 0; i--)
    {
        for (int j = 0; j < alpha[i] / 2; j++)
        {
            palindrome += 'A' + i;
        }
    }

    // 부분 다 더한 값 리턴
    return palindrome;
}

int main()
{
    vector<int> alpha(ALPHA, 0);
    string name;
    cin >> name;
    for (char ch : name)
    {
        alpha[ch - 'A']++;
    }
    cout << getPalindrome(alpha);
}