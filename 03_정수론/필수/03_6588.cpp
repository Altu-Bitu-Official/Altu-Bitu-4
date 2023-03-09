#include <iostream>
#include <vector>


using namespace std;


vector<int> prime(int n){
    vector<int> fac(n+1,1);
    for(int i=2; i*i<=n; i++){
        if(fac[i]==1){
            for(int j=i*i; j<=n; j+=i){
                fac[j]=0;
            }
        }
    }
    return fac;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> fac = prime(n);

    while(1){
        bool flag = false;
        cin >> n;

        if(n==0){
            break;
        }

        for(int i=3; i<=n; i +=2){
            if(fac[i]==1 && fac[n-i]==1){
                flag = true;
                cout << n << " = " << i << " + " << n-i << "\n";
                break;
            }
        }
        if(!flag){
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}