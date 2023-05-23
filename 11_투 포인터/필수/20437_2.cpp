// 문자열 게임 2

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void shortString(string w, int k){
    map<char, vector<int>> alphabet_idx; // 문자열 w에서 알파벳 별 인덱스 저장
    
    int min_len = w.length(), max_len = 0; 
    
    for (int i = 0; i < w.length(); i++){
        alphabet_idx[w[i]].push_back(i);
        
        int len = alphabet_idx[w[i]].size(); // 알파벳 개수
        if (len >= k){
            min_len = min(min_len, alphabet_idx[w[i]][len-1] - alphabet_idx[w[i]][len-k] + 1); // 인덱스 차이 (문자열 길이)
            max_len = max(max_len, alphabet_idx[w[i]][len-1] - alphabet_idx[w[i]][len-k] + 1);
        }
    }
    if (max_len == 0){ // max_len에 변경이 없으면 (가능한 문자열이 존재하지 않으면)
        cout << -1 << '\n';
    }
    else{
        cout << min_len << " " << max_len << '\n';
    }
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