#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> ci; //구조체 선언 

//mymin, mymax를 리턴 
ci calNum(string w, int k){
    vector<vector<int>> positions(26);
    for (int i = 0; i < w.length(); i++) {
        positions[w[i] - 'a'].push_back(i);
        //알파벳 별로 해당 문자 나타난 위치 저장하는 벡터 
    }
    
    int mymin= w.length() + 1, mymax = 0; 
    for (int i = 0; i < 26; i++) {
        if (positions[i].size() < k) {
            continue; 
            //size가 k보다 작은 경우 mymin, mymax가 될 수 없음 
        }
        int left = 0, right = k - 1; //left, right 초기화 
        while (right < positions[i].size()) {
            int len = positions[i][right] - positions[i][left] + 1;
            mymin = min(mymin, len); //mymin 갱신  
            mymax = max(mymax, len); //mymax 갱신 
            left++;
            right++;
        }
    }
    ci ans = {mymin, mymax}; //{mymin, mymax} 쌍 반환 
    return ans;
}


int main() {
    //입출력 향상 
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    //입력 
    int t;
    cin >> t;
    
    while (t--) {
        string w;
        int k;
        cin >> w >> k;
        //연산
        ci ans = calNum(w, k);
        
        //출력
        if (ans.first == w.length() + 1) {
            cout << "-1\n";
        } 
        else {
            cout << ans.first << " " << ans.second << "\n";
        }
    }
    
    return 0;
}