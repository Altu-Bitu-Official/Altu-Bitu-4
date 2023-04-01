#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int PutFirstWord(string input, vector<int> &first_word)
{
    for (int i = 0; i < input.length(); i++)
    {
        int num;
        char ch = input[i];
        switch (ch)
        {
        case 'A':
            num = 0;
            break;
        case 'B':
            num = 1;
            break;
        case 'C':
            num = 2;
            break;
        case 'D':
            num = 3;
            break;
        case 'E':
            num = 4;
            break;
        case 'F':
            num = 5;
            break;
        case 'G':
            num = 6;
            break;
        case 'H':
            num = 7;
            break;
        case 'I':
            num = 8;
            break;
        case 'J':
            num = 9;
            break;
        case 'K':
            num = 10;
            break;
        case 'L':
            num = 11;
            break;
        case 'M':
            num = 12;
            break;
        case 'N':
            num = 13;
            break;
        case 'O':
            num = 14;
            break;
        case 'P':
            num = 15;
            break;
        case 'Q':
            num = 16;
            break;
        case 'R':
            num = 17;
            break;
        case 'S':
            num = 18;
            break;
        case 'T':
            num = 19;
            break;
        case 'U':
            num = 20;
            break;
        case 'V':
            num = 21;
            break;
        case 'W':
            num = 22;
            break;
        case 'X':
            num = 23;
            break;
        case 'Y':
            num = 24;
            break;
        case 'Z':
            num = 25;
            break;
        }
        first_word[num] = first_word[num] + 1;
    }
    return 1;
}
bool CheckSimilar(string input, vector<int> &first_word)
{
    vector<int> similar = first_word;
    // 만일 값이 없는 경우 0을 넣어줘야하므로 처음에 0으로 초기화해야하는데 이걸 안함
    for (int i = 0; i < input.length(); i++)
    {
        int num;
        char ch = input[i];
        switch (ch)
        {
        case 'A':
            num = 0;
            break;
        case 'B':
            num = 1;
            break;
        case 'C':
            num = 2;
            break;
        case 'D':
            num = 3;
            break;
        case 'E':
            num = 4;
            break;
        case 'F':
            num = 5;
            break;
        case 'G':
            num = 6;
            break;
        case 'H':
            num = 7;
            break;
        case 'I':
            num = 8;
            break;
        case 'J':
            num = 9;
            break;
        case 'K':
            num = 10;
            break;
        case 'L':
            num = 11;
            break;
        case 'M':
            num = 12;
            break;
        case 'N':
            num = 13;
            break;
        case 'O':
            num = 14;
            break;
        case 'P':
            num = 15;
            break;
        case 'Q':
            num = 16;
            break;
        case 'R':
            num = 17;
            break;
        case 'S':
            num = 18;
            break;
        case 'T':
            num = 19;
            break;
        case 'U':
            num = 20;
            break;
        case 'V':
            num = 21;
            break;
        case 'W':
            num = 22;
            break;
        case 'X':
            num = 23;
            break;
        case 'Y':
            num = 24;
            break;
        case 'Z':
            num = 25;
            break;
        }
        similar[num] = similar[num] - 1;
    }
    int count_1 = 0;
    int count_2 = 0;
    for (int i = 0; i < similar.size(); i++)
    {
        if (similar[i] != 0 && similar[i] != 1 && similar[i] != -1)
        {
            return false;
        }
        if (similar[i] == 1)
        {
            count_1++;
        }
        if (similar[i] == -1)
        {
            count_2++;
        }
    }
    if (count_1 == 1 && count_2 == 1)
    {
        return true;
    }
    else if (count_1 + count_2 > 1)
    {
        return false;
    }
    return true;
}

int main()
{
    // 길이가 26인 벡터에 각 알파벳이 사용된 횟수 넣기-> 첫번쨰 단어에 대해
    // 두번째부터는 pop하면서 확인하기
    int n;
    cin >> n;
    vector<int> first_word(26, 0);
    // 만일 값이 없는 경우 0을 넣어줘야하므로 처음에 0으로 초기화해야하는데 이걸 안함
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        string k;
        cin >> k;
        if (i == 0)
        {
            PutFirstWord(k, first_word);
            // 여기서부터 실행 안됨
        }
        else
        {
            if (CheckSimilar(k, first_word))
            {
                count++;
            }
        }
    }
    cout << count;
    return 0;
}