#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int num[200001];
int cnt[100001];
void sol(int k, int n){
    
    int ans=0;
    int start=1;
    int end=1;

    while(start<=end&&end<=n){
        if(cnt[num[end]]<k){
            cnt[num[end++]]++;
            ans=max(ans, end-start);
        }
        else if(cnt[num[end]]==k){
                cnt[num[start++]]--;
        }
    }
    cout<< ans;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    
    int tmp;
    for(int i=1;i<=n;i++){
        cin >> tmp;
        num[i]=tmp;
    }

    sol(k,n);
}