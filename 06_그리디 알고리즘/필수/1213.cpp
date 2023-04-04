#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string nickname, palindrom = "";
    cin >> nickname;

    vector<char> new_name;

    for (int i = 0; i < nickname.length(); i++)
    {
        new_name.push_back(nickname[i]);
    }
    sort(new_name.begin(), new_name.end());

    vector<char> name_return(new_name.size(), 0);

    // i가 홀수인지 짝수인지로 나눈다면?
    if (new_name.size() % 2 == 0)
    { // 전부 짝수개여야 함
        for (int i = 0; i < new_name.size(); i++)
        {
            int num = i / 2;
            if (i % 2 == 0)
            {
                name_return[num] = new_name[i];
            }
            else
            {
                name_return[name_return.size() - 1 - num] = new_name[i];
            }
        }
    }
    else
    {
        int i = 0;
        while (i < new_name.size())
        {
            int num = i / 2;
            if (new_name[i] == new_name[i + 1])
            {
                name_return[num] = new_name[i];
                name_return[name_return.size() - 1 - num] = new_name[i + 1];
                i += 2;
            }
            else
            {
                if (name_return[name_return.size() / 2] == 0)
                {
                    name_return[name_return.size() / 2] = new_name[i];
                    i += 1;
                }
                else
                {
                    // 만일 홀수 개인게 이미 있었을 경우
                    cout << "I'm Sorry Hansoo";
                    return 0;
                }
            }
        }
    }
    for (int i = 0; i < name_return.size(); i++)
    {
        palindrom += name_return[i];
    }
    string compare_palindrom = palindrom;
    reverse(compare_palindrom.begin(), compare_palindrom.end());
    if (compare_palindrom == palindrom)
    {
        cout << palindrom;
    }
    else
    {
        cout << "I'm Sorry Hansoo";
    }
    // 그냥 여기서 reverse해서 다르면 out시킬 것
    return 0;
}