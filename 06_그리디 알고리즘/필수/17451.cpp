#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    long long N; cin >> N;

    vector<long long> v(N,0);
    for(long long i=0; i<N; i++) {
        cin >> v[i];
    }
    long long ans = 0;
    for(long long i=N-1; i>=0; i--) {
        if(ans <= v[i]) {
            ans = v[i];
        }
        else if(ans % v[i] != 0){
             ans = (ans / v[i] + 1) * v[i];
        }
    }
    cout << ans ;
}