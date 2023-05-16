#include <iostream>
#include <vector>

using namespace std;
const int NUM_CHARS = 26;

/*
 * 원본 단어와의 차이의 개수를 센다.
 */

/*
 * [비슷한 단어]
 *
 * 단어가 같은 구성일 조건
 * 1. 두 개의 단어가 같은 종류의 문자로 이루어짐
 * 2. 같은 문자는 같은 개수만큼 있음
 *
 * 비슷한 단어의 조건
 * 1. 한 단어에서 한 문자를 더하거나, 빼면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 1개
 * 2. 한 단어에서 한 문자를 바꾸면 같은 구성이 됨
 *    -> 두 단어에서 다른 문자의 개수가 총 2개
 *    -> !주의! 이때, 두 단어의 길이가 같아야 함 cf) doll | do
 */

// 각 알파벳의 개수 세기
void countFreq(string word, vector<int> &freq)
{
    for (int i = 0; i < word.length(); i++)
    {
        freq[word[i] - 'A']++;
    }
}

int countDiff(string word, vector<int> original_freq)
{
    vector<int> freq(NUM_CHARS, 0);
    int diff = 0; // 원본 단어와의 차이

    countFreq(word, freq); // 각 알파벳의 개수 세기

    // 원본 단어와 다른 알파벳 개수 구하기
    for (int i = 0; i < NUM_CHARS; i++)
    {
        diff += abs(original_freq[i] - freq[i]);
    }
    return diff;
}

int main()
{
    int N, ans = 0;
    string original;
    // 입력
    cin >> N;
    cin >> original;
    vector<int> original_freq(NUM_CHARS, 0);

    // 연산
    countFreq(original, original_freq);

    for (int i = 1; i < N; i++)
    {
        string word;
        cin >> word;

        int diff = countDiff(word, original_freq);
        // 비슷한 단어 세기
        if (diff == 0 || diff == 1 || diff == 2 && original.length() == word.length())
        {
            ans++;
        }
    }
    // 출력

    cout << ans;
    return 0;
}