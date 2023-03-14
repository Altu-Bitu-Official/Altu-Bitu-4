//
// Created by LG on 2023-03-07.
//
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(0);

    vector<bool> is_prime(1000001, true);
    for(int i=2; i<=sqrt(1000001); i++){
        if(is_prime[i]){
            for(int j=i*i; j<=1000001; j += i){
                is_prime[j] = false;
            }
        }
    }

    while(true){
        int n, a, b;
        cin >> n;

        if(n == 0)
            break;

        for(int i=3; i<=n/2; i++){
            if(is_prime[i] && is_prime[n-i]) {
                a = i;
                b = n - i;
                break;
            }
        }

        cout << n << " = " << a << " + " << b << '\n';

    }
}
