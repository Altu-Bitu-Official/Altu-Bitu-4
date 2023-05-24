#include <iostream>
#include <vector>
#define INT_MAX 10000
using namespace std;

int main(){
    int t, k;
    string w;
    cin >> t;

    for(int i=0;i<t;i++){
        cin>>w;
        cin>>k;
        vector<int> alpha[26];
        int ans1=INT_MAX;
        int ans2=-1;

        for(int j=0;j<w.length();j++){
            alpha[w[j]-'a'].push_back(j);
        }

        for(int j=0;j<26;j++){
            if(alpha[j].size()>=k){
                int start=0;
                int end=k-1;
                int tmp1=alpha[j][end]-alpha[j][start]+1;
                int tmp2=alpha[j][end]-alpha[j][start]+1;
                while(end<alpha[j].size()-1){
                    end++;
                    start++;
                    tmp1=min(alpha[j][end]-alpha[j][start]+1, tmp1);
                    tmp2=max(alpha[j][end]-alpha[j][start]+1, tmp2);
                }
                ans1=min(tmp1,ans1);
                ans2=max(tmp2, ans2);
            }
        }
        if(ans1==INT_MAX){
            cout << -1 <<"\n";
        }
        else{
            cout<< ans1 <<" "<<ans2<<"\n";
        }
    }
    

    
}