#include <iostream>

using namespace std;

int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, i, ans; cin >> N;

    while(N){
        for ( i =666; ; i++){
            while (i){
                if (i%1000 == 666){
                    ans = i;
                    N--;
                }
                else{
                    i=i/10;
                }
            }
        }
    }
    cout << ans;   // 시간초과 해결 방법?
    return 0;
}