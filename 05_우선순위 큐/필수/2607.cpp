#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void countFreq(string word, vector<int> &freq) // 입력받은 문자열에서 각 알파벳의 개수를 세주는 함수
{
    for (int i = 0; i < word.length(); i++)
    {                          // 문자열의 개수만큼 반복
        freq[word[i] - 'A']++; // 인덱스를 A(0)로부터 저장
    }
}

int countDiff(string word, vector<int> ori_freq) // ori기준으로 매개변수 word와 ori의 차이를 반환하는 함수
{
    // 새로 입력받은 단어 word의 알파벳 개수 저장
    vector<int> freq(26, 0); // 알파벳개수 26개를 0으로 초기화

    // 원본 단어와의 차이를 저장할 변수
    int diff = 0; // 1씩 증가시키기위해 0으로 초기화

    // 새로 입력받은 단어의 알파벳 수
    countFreq(word, freq);

    for (int i = 0; i < 26; i++) // 새로받은 단어와 비교
    {
        diff += abs(ori_freq[i] - freq[i]); // 원본과 새로운 단어의 빈도수 차이를 저장
    }

    return diff; // 차이값 반환
}

int main()
{
    int N;
    int ans = 0; // +1씩 초기화하기 위해 0으로 초기화
    string ori;  // 원본 단어(첫번째로 입력받는 단어)

    cin >> N;
    cin >> ori; // 원본단어 사용자 정의

    // 각 알파벳의 개수를 저장할 정수형 벡터
    vector<int> ori_freq(26, 0); // 알파벳이 26개, 개수를 세야하니 0으로 초기화

    countFreq(ori, ori_freq); // ori의 각 알파벳에 대한 개수를 count

    for (int i = 1; i < N; i++) // i =0 은 ori이니 1부터 count
    {
        string word;
        cin >> word; // 단어 사용자 입력

        // 현재 입력 단어와 원본 단어 사이의 차이
        int diff = countDiff(word, ori_freq);

        if (diff == 0 || diff == 1 || (diff == 2 && ori.length() == word.length()))
        { // 1,2,3번의 조건중에 하나라도 만족할 경우
            ans++;
        }
    }
    cout << ans;
    return 0;
}