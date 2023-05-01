#include <iostream>
#include <vector>

using namespace std;
const int NUM_CHARS = 26;

int getDifference(string word, vector<int> original_freq){
    vector<int> freq(NUM_CHARS, 0);
    int difference = 0; // 원본 단어와의 차이

    for (int i=0; i<word.length(); i++){
        // 해당하는 알파벳에 개수를 증가시켜준다.
        freq[word[i] - 'A']++;
    }
    // 원본 단어와 다른 알파벳 개수 구하기
    for (int i=0; i<NUM_CHARS; i++){
        difference += abs(original_freq[i]-freq[i]);
    }
    // 다른 알파벳 개수 반환
    return difference;
}

int main() {
    int n, result=0;
    string original;
    vector<int> original_freq(NUM_CHARS, 0);

    // 입력
    cin >> n >> original;

    for (int i=0; i<original.length(); i++){
        // 해당하는 알파벳의 개수를 증가시켜준다.
        original_freq[original[i] - 'A']++;
    }

    for (int i=1; i<n; i++) {
        // 단어 입력
        string word;
        cin >> word;
        // countDiff 연산
        int diff = getDifference(word, original_freq);
        // diff값이 0,1이거나 2이지만 글자길이가 똑같다면
        if (diff == 0 || diff == 1 || diff == 2 && original.length() == word.length()){
            //비슷한 단어이므로 ans증가
            result++;
        }
    }
    // 출력
    cout << result;
}