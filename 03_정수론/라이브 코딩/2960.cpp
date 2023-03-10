// 에라토스테네스의 체

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int isPrime(int n, int k, vector<bool> &is_prime){
    int cnt = 0;
    is_prime[0] = is_prime[1] = false;
    for (int i=2; i<=n; i++)
        if (is_prime[i]) // i가 소수라면
            for (int j=i; j<=n; j+=i){
                is_prime[j] = false; // i의 배수를 제거
                if ((++cnt) == k)
                    return j;
            }
    return -1;
}

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector <bool> is_prime(n+1, true);
    cout << isPrime(n, k, is_prime);
    
    return 0;
}