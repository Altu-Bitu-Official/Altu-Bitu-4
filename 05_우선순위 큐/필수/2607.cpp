#include <iostream>
#include <vector>

using namespace std;

void countAlphabet( string word, vector<int> &count){
    for( int i =0; i<word.length();i++){ //굳이 string을 char로 바꿔줄 필요 없이 바로 배열로
        count[word[i] - 'A']++;
    }
}

int countDiff(string word, vector<int> base_alp){
    vector<int> freq(26,0);
    int diff = 0;

    countAlphabet(word,freq);

    for( int i = 0; i< 26; i++){
        diff += abs(base_alp[i] - freq[i]);
    }
    return diff;
}

int main(){
    int n, ans=0;
    string base;
    cin >> n;
    cin >> base;
    vector<int> base_alp(26,0); //0으로 초기화. 이때 26은 알파벳 개수

    countAlphabet(base, base_alp); //연산 - 각 알파벳 개수 몇개인지 count

    for( int i =1; i<n; i++){
        string word;
        cin>>word;

        int diff = countDiff(word, base_alp);

        if( diff == 0 || diff ==1 || diff ==2 && base.length() == word.length()){
            ans++;
        }
    }
    cout <<ans;
    return 0;
}