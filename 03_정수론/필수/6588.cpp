#include <iostream>
#include <vector>

const int MAX  = 1000000; 

using namespace std;

vector<int> getPrimes() {
    vector<int> primes(MAX + 1, 0);
    for(int i = 2; i * i <= MAX; i++) {
        if(primes[i] != 0) { 
            continue;
        }
        
        for(int j = i * i; j <= MAX; j += i) {
            if (primes[j] == 0) {
                primes[j] = i;
            }
        }
    }
    return primes;
}

vector<int> getPrimeFactors(int k, vector<int> &primes) {
    vector<int> factors; 

    while(primes[k] != 0) { 
        factors.push_back(primes[k]);
        k /= primes[k];
    }
    factors.push_back(k);
    return factors;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin>>n;

    vector<int> primes = getPrimes();
    vector<int> factors = getPrimeFactors(k, primes);

   while (true){
        int n;
        cin >> n;

        if (n == 0)
            break;
        
        for (int i = 0; i < factors.size(); i++){
            if (primes[n - factors[i]] == n - factors[i])
            {
                cout << n << " = " << factors[i] << " + " << n - factors[i] << '\n';
                break;
            }
        }
    }
    return 0;
}
