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

const int NUM_CHARS = 26;//알파벳은 26개

//각 알파벳의 개수 세기
void countFreq(string word, vector<int>& freq) {//original, original_freq
    for (int i = 0; i < word.length(); i++) {//원래문자열 길이만큼 for문 돌리기
        freq[word[i] - 'A']++;//그 알파벳을 ++한다. (original에 들어있는 알파벳이 뭔지)
    }
}

int countDiff(string word, vector<int> original_freq) {//다음으로 입력받은 단어들과 아까 알파벳 갯수만큼 ++해놨던 그 벡터
    vector<int> freq(NUM_CHARS, 0);//또 벡터를 생성
    int diff = 0; // 원본 단어와의 차이

    countFreq(word, freq); //각 알파벳의 개수 세기

    //원본 단어와 다른 알파벳 개수 구하기
    for (int i = 0; i < NUM_CHARS; i++) {//알파벳수만큼
        diff += abs(original_freq[i] - freq[i]);//둘이 값들을 빼면 얼마만큼 차이나는지가 나올 것임(같은 알파벳이면 0이겠지만 아니거나 갯수 다르면)
    }
    return diff;//차이나는 갯수를 리턴
}

int main() {
    int N, ans = 0;//단어 갯수, 답안
    string original;//첫번째 문자열
    //입력
    cin >> N;//단어갯수
    cin >> original;//첫번째 문자열
    vector<int> original_freq(NUM_CHARS, 0);//원래값을 다 0으로 초기화(알파벳)


    countFreq(original, original_freq); //연산

    for (int i = 1; i < N; i++) {//단어들을 다 체크
        string word;//그 다음으로 나오는 단어들을 비슷한 단어인지 체크할것임
        cin >> word;//입력받는다. 

        int diff = countDiff(word, original_freq);//차이나는 갯수가 리턴됨 
        //비슷한 단어 세기
        if (diff == 0 || diff == 1 || (diff == 2 && original.length() == word.length())) {//비슷하려면 둘이 길이 같아야한다는 2번째 조건 , 다른게 1개나 2개까지만 비슷한 단어가 될 수 있음(그 이상은 안 됨)
            //||diff == 2 && original.length() == word.length()으로 조건문 처리. 따라서 헷갈리지 말자(단어차이가 2개고 길이가 같은 것: 2번 조건) 
            ans++;//비슷한단어면 답안에 추가
        }
    }
    //출력
    cout << ans;//답안
    return 0;
}