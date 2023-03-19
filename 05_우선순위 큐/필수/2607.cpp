// 비슷한 단어

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

int isSimilar(vector<char> s1, string word, string x){
    // 문자x를 구성하는 알파벳 벡터 생성
    vector<char>s2;
    for (int i=0; i<x.size(); i++)
        s2.push_back(x[i]);
    sort(s2.begin(), s2.end());
    
    // 두 집합의 대칭차집합 구하기
    vector<char> diff;
    set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(diff, diff.begin()));
    
    // 대칭차집합 원소가 1개이하인 경우 - 같은 구성을 갖는 경우, 하나의 문자를 더하거나 빼는 경우
    if (diff.size() <= 1)
        return 1;
        
    // 한 문자를 다른 문자로 바꿔야하는 경우
    if (word.size() == x.size() && diff.size() == 2) // 길이는 같고 대칭차집합은 2
        return 1;
    return 0;
}

int main()
{   
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, cnt = 0;
    string word, x;
    vector<char> s1;
    cin >> n;
    cin >> word; // 첫번재 단어
    
    // 첫번째 단어의 구성 벡터 만들기
    for (int i=0; i<word.size(); i++)
        s1.push_back(word[i]);
    sort(s1.begin(), s1.end());
    
    while (--n){
        cin >> x;
        cnt += isSimilar(s1, word, x); // 첫 번째 단어와 비슷하면
    }
    cout << cnt;
    return 0;
}