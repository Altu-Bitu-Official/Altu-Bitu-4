#include <iostream>
#include <vector>

using namespace std;

int cntSubseq(int k,int n,vector<int> &seq){
    int left =0, right =1;
    int cnt =1;
    int ans = cnt;
    vector<int> num (200001,0);
    num[seq[left]]++;
    while(right<n){
        if(num[seq[right]] <k){
            cnt++;
            num[seq[right++]]++;

        }else{
            while(num[seq[right]]==k){
                num[seq[left]]--;
                left++;
                cnt--;
            }

        }

        if(ans < cnt){
            ans = cnt;
        }


    }
    return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >>k;
    vector <int> seq(n,0);

    for( int i=0;i<n;i++){
        cin >>seq[i];
    }
    cout << cntSubseq(k,n,seq);


    return 0;
}
