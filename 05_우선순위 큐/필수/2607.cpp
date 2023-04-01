#include <iostream>
#include <vector>

using namespace std;

bool isSimilar(string word1, string word2, int diff) {
    //기준(첫번째 단어) 알파벳 배열
    vector<int> alpha(26, 0);
    //비교할 알파벳 배열
    vector<int> cmpAlpha(26, 0);

    int result=0;
    int flag=0;

    for(int i=0; i<word1.length(); i++) {
        alpha[word1[i]-'A']++;
    }
    for(int i=0; i<word2.length(); i++) {
        cmpAlpha[word2[i]-'A']++;
    }

    for(int i=0; i<26; i++) {
        result+=abs(alpha[i]-cmpAlpha[i]);
        //알파벳 사용된 횟수 차이 1이면 flag 증가
        if(abs(alpha[i]-cmpAlpha[i])==1) {
            flag++;
        } else if(abs(alpha[i]-cmpAlpha[i])>1) {
            //알파벳 사용된 횟수 차이 2 이상이면 길이 같거나 다를 때 모두 같은 구성 만들 수 없으므로 거짓
            return false;
        }
    }

    //길이 같고 flag 증가 2번 된 거면 한 글자 바꿔서 같은 구성 만들 수 있으므로 참
    if(diff==0 && (flag==2)) {
        return true;
    }
    //단어 길이 차 1이고 사용된 알파벳 횟수 차 1이거나 단어 길이 같고 사용된 알파벳 횟수 같으면 참
    if(abs(result)==diff) {
        return true;
    }
    //그 외 거짓
    return false;
}

int main() {
    int n;
    cin >> n;

    int result=0;

    vector<string> words(n);
    for(int i=0; i<n; i++) {
        cin >> words[i];
    }

    for(int i=1; i<n; i++) {
        int diff=words[0].length()-words[i].length();

        if(diff==0 && isSimilar(words[0], words[i], 0)) {
            result++;
        }
        if(abs(diff)==1 && isSimilar(words[0], words[i], 1)) {
            result++;
        }
    }

    cout << result;

    return 0;
}