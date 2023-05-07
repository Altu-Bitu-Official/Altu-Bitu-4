// 골드바흐의 추측

#include <iostream>
#include <vector>

using namespace std;

void sosu(vector<bool> &s, int n){
    for (int i=3; i*i<=n; i+=2)
        if (s[i])
            for (int j=i*i; j<=n; j+=2)
                if (j%i == 0)
                    s[j] = false;
}

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    int n = 100000;
    vector<bool> s(n+1, true);
    sosu(s, n);
    int k;
    while (1){
        cin >> k;
        if (k == 0)
            break;
        int ans = 0;
        for (int i=3; i<=(k/2); i+=2){
            if (s[i] && s[k-i]){
                ans = 1;
                cout << k << " = " << i << " + " << (k-i) << '\n';
                break;
            }
        }
        if (ans == 0)
           cout << "Goldbach's conjecture is wrong."; 
    }
    return 0;
}
