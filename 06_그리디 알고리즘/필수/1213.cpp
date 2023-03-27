// 팰린드롬 만들기

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int palindrome(vector<string> words, int n){
    int odd = 0, idx = 0;
    vector<string> ans(n);
    
    if (n == 2){
        if (words[0] == words[1])
            cout << words[0] << words[1];
        else
            cout << "I'm Sorry Hansoo";
        return 0;
    }
    
    // 만들 수 있는 문자열인지 확인
    for (int i = 0; i < n; i ++){
        if (i==0 || (words[i] != words[i-1])){ // 이전 문자와 다르다면
            int m = count(words.begin(), words.end(), words[i]); // 개수 count
            if (m %2 == 1){ // 홀수 개 있으면
                odd++; idx = i;
            }
        }
    }
    if (odd > 1){ // 홀수번 등장한 문자가 2개 이상이면 만들 수 없음
        cout << "I'm Sorry Hansoo";
    }
    else{
        if (odd == 1){
        ans[n/2] = words[idx];
        words.erase(words.begin()+idx);
        }
        for (int i=0; i<words.size(); i+=2){
            ans[i/2] = words[i];
            ans[words.size()-(odd==0)-i/2] = words[i+1];
        } 
        for (int i=0; i<n; i++){
            cout << ans[i];
        }
    }
    return 0;
}

int main()
{
    string x;
    cin >> x;
    int n = x.length();
    vector<string> words(n);
    // 입력
    for (int i=0; i<n; i++){
        words[i] = x[i];
    }
    sort(words.begin(), words.end()); // 정렬
    palindrome(words, n);
    
    return 0;
}