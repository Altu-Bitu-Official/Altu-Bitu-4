#include <iostream>

using namespace std;

// 첫 번째 단어와 입력받은 문자열을 비슷한 단어인지 판단하는 함수
bool checkSimilar(string first_vocab, string& input) {
    int same_cnt = 0, in_len = input.length();
    if (in_len <= first_vocab.length() + 1 && in_len >= first_vocab.length()-1) {

        for (char c : input) {
            for (int i = 0; i < first_vocab.length(); i++) {
                if (c == first_vocab[i]) {
                    same_cnt++;    //동일한 알파벳일 경우 카운트 증가
                    first_vocab.erase(i, 1);    //그 후 첫 번째 단어에서 그 알파벳 제거    
                    break;
                }
            }
        }
        //1. input이 포함하는 알파벳이 첫 번째 단어와 비교해서 +=1 차이 2. 첫 번째 단어에 남아있는 알파벳 개수가 1 이하
        if (first_vocab.length() <= 1 && same_cnt <= in_len+1 && same_cnt >= in_len-1) {
            return true;
        }    
    }
    return false;
}

int main() {
    int n, cnt = 0;
    string first_vocab;

    //입력
    cin >> n >> first_vocab;

    for (int i = 0; i < n-1; i++) {
        string input;
        cin >> input;
        if(checkSimilar(first_vocab, input)) {
            cnt++;    //유사할 경우 카운트 증가          
        }
    }
    //출력
    cout << cnt;
}