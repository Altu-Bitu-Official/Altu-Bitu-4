#include <iostream>
#include <vector>

using namespace std;
const int MAX = 10001;
typedef pair<int, int> ci;

ci solution(string w, int k, vector<int> alp){
    int ans = MAX;
    int ans2 = -1;

    for(int i=0; i<w.length(); i++){
        if(alp[w[i]-97] < k){
            continue;
        }
        //해당 알파벳이 k 이상이라면
        int count = 0;
        for(int j=i; j<w.length(); j++){
            if(w[j] == w[i])    //같은 알파벳 찾으면 +1
            {
                count++;
            }
            if(count == k){
                ans = min(ans, j-i+1);
                ans2 = max(ans2, j-i+1);
                break;
            }
        }
    }

    ci result = {ans, ans2};
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t, k;   //t : 문자열 게임 수
    string w;
    
    vector<int> alp;  
    alp.assign(26, 0);  //알파벳 개수만큼 초기화 alp[0]=a, alp[25]=z

    //입력
    cin >> t;
    
    while(t--){
        cin >> w >> k;
        for(int i=0; i<w.length(); i++){
            alp[w[i]-97]++;
        }

        ci ans = solution(w, k, alp);
        if(ans.first == MAX || ans.second == -1){
            cout << -1 << "\n";
        }
        else{
            cout << ans.first << " " << ans.second << "\n";
        }
        
    }
    
}