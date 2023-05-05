// 16401 과자 나눠주기
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
bool chk(ll &mid, vector<ll> &cookie, ll &M){
    ll sum = 0;
    for(int i = 0; i < cookie.size(); i++){
        sum += cookie[i]/mid;
    }
    if(sum >= M) {
        return true;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll M, N; // 조카의 수: M, 과자의 수 : N
    ll sum = 0;
    cin >> M >> N;
    vector<ll> cookie;
    while(N--){
      ll x;
      cin >> x;
      cookie.push_back(x);
    }
    ll lo = 1;
    ll hi = *max_element(cookie.begin(), cookie.end());
    ll mid;
    ll ans = 0;
    while(lo <= hi){
        mid = (lo + hi)/2;
        if(chk(mid, cookie, M)) {
            lo = mid + 1;
            ans = mid;
        }
        else {
            hi = mid - 1;
        }
    }
    cout << ans << "\n";
}