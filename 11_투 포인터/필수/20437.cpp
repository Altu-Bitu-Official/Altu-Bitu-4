#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> ci;


ci containK(int k, string w, vector<int> &al){
    int len,max_len=-1,min_len=10001;

    for (int i =0;i<w.length();i++){
        if(al[w[i]-'a']<k){
            continue;
        }
        int cnt =0;
        for(int j =i;j<w.length();j++){
            if(w[i]!=w[j])
                continue;
                cnt ++;
                if(cnt == k){
                    len = j-i+1;
                    max_len =max(len,max_len);
                    min_len = min(len,min_len);
                    break;
                }
            }
    }
    return {min_len,max_len};
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t,k;
    string w;
    cin >> t;
    while(t--){
        vector<int> al (26,0);
        cin >>w >> k;
        for (int i =0;i<w.length();i++){
            al[w[i]-'a']++;
        }
        ci ans=containK(k,w,al);
        if(ans.second ==-1 || ans.first ==10001){
            cout <<-1;
        }else{
            cout <<ans.first<<" "<<ans.second;
        }
        cout<<"\n";
    }
}
