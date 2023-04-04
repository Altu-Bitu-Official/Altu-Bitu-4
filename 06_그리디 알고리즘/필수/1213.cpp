#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int NUM_CHARS = 26;

void countAlp(string word, vector<int> &alp){
    for(int i=0; i<word.length();i++){
        alp[word[i]-'A']++;      //각 알파벳의 개수 세기
    }
}

int oddEven(string word, vector<int> count_alp){
    vector<int> alp(NUM_CHARS,0);
    int num=0;
    
    for(int i=0; i<NUM_CHARS; i++){
        alp[i] = count_alp[i]%2;  // 홀수면 alp에 1 저장, 짝수면 alp에 0 저장
        if(alp[i] == 1){
            num++;
        }

    }
    return num;
}

void answer(string word, vector<int> count_alp){
    int size = word.size();
    char alphabet = 'A';
    int n=0;
    vector<char> solve(size);

    for( int i=0; i<NUM_CHARS; i++){
        int num = count_alp[i]/2;
        if(count_alp[i] !=0){
            for( int j =n; j<n+num; j++){
                solve[j] = alphabet;
            }
            for( int j = size-1-n; j>size-1-n-num; j--){
                solve[j] = alphabet;
            }
            if(count_alp[i]%2 ==1){
                solve[size/2] = alphabet;
            }
        }
        n+=num;
        alphabet++;
    }
    
    for(int i=0; i<size; i++){
        cout<<solve[i];
    }
}

int main(){
    string word;
    int size = word.size();
    cin >> word;
    vector<int> count_alp(NUM_CHARS,0);
    vector<char> ans(size);

    countAlp(word, count_alp);

    int num = oddEven(word,count_alp);

    if( num >=2 ){
        cout << "I'm Sorry Hansoo" ;
    }
    else{
        answer(word,count_alp);
    }
    return 0;  
}