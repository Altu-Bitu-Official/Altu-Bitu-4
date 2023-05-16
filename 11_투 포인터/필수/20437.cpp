// 문자열 게임 2 - 시간 초과

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// 길이가 i인 문자열에서 탐색
int findLen(int i, string w, int k){
    vector<int> alphabet(26, 0); // 알파벳 별 개수 count
    
    for (int j = 0; j < i; j++){ // i개의 문자열 우선 탐색
        alphabet[w[j] - 'a']++;
    }
    if (alphabet[w[0] - 'a'] == k and (w[0] == w[i-1])){
        return i;
    } 
    for (int j = i; j < w.length(); j++){
        alphabet[w[j-i] - 'a']--;
        alphabet[w[j] - 'a']++;
        if (alphabet[w[j] - 'a'] == k and w[j] == w[j-i+1]){
            return i;
        }
    }
    return -1;
}

void shortString(string w, int k){
    int x;
    for (int i = k; i <= w.length(); i++){ // 길이가 i인 문자열 살펴보기
        x = findLen(i, w, k);
         
        if (x != -1){ // 길이가 i인 문자열이 가능하면
            cout << x << ' ';
            break;
        }
    }
    if (x == -1){ // 가능한 문자열이 없다면
        cout << -1 << '\n';
        return; // 바로 종료
    }
    for (int i = w.length(); i >= k; i--){
        x = findLen(i, w, k);
        if (x != -1){ // 길이가 i인 문자열이 가능하면
            cout << x << '\n';
            break;
        }
    }
    return;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    int t, k;
    string w;
    cin >> t;
    while (t--){
        cin >> w >> k;
        shortString(w,k);
    }
    return 0;
}