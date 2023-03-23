#include <iostream>
#include <vector>

using namespace std;
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

const int NUM_CHARS = 26; //알파벳의 개수 26개

//각 알파벳의 개수 세기
void countFreq(string word, vector<int> &freq) {//원본 단어를 정수형으로 벡터에 저장하는 함수
    for (int i = 0; i < word.length(); i++) {
        freq[word[i] - 'A']++; //입력 받은 알파벳에서 A를 빼주어 저장함(ex: A=0, B=1 ....)
    }
}

int countDiff(string word, vector<int> original_freq) {//원본 단어와 차이를 세는 함수
    vector<int> freq(NUM_CHARS, 0);// 26개를 0으로 초기화-비교할 단어가 들어감
    int diff = 0; // 원본 단어와의 차이

    countFreq(word, freq); //함수를 호출해 각 알파벳의 개수 세기
    
    //원본 단어와 다른 알파벳 개수 구하기
    for (int i = 0; i < NUM_CHARS; i++) {
        diff += abs(original_freq[i] - freq[i]);//orignal_freq(처음에 입력 받은 기준 단어)-freq(비교할 단어)
    }
    return diff; //차이값return
}

int main() {
    int N, ans=0; 
    string original;
    //입력
    cin >> N;
    cin >> original;
    vector<int> original_freq(NUM_CHARS, 0);//오리지널 단어가 들어갈 벡터 초기화

    //연산
    countFreq(original, original_freq);//오리지널 단어를 연산

    for (int i = 1; i < N; i++) {//이때 오리지널 단어는 이미 입력 받았으므로 N-1만큼 입력 받음
        string word;
        cin >> word;//비교할 단어 입력 받음

        int diff = countDiff(word, original_freq);
        //비슷한 단어 세기
        if (diff == 0 || diff == 1 || diff == 2 && original.length() == word.length()) {
            ans++; //구성이 같음(0), 문자 하나만 빼거나 더함(1), 한문자를 다른 문자로 바꿈(2, 길이 동일)
        }
    }
    //출력
    cout << ans; // 비슷한 단어의 개수 출력
    return 0;
}
