#include <iostream>
#include <vector>
#include <cmath>

const int MAX = 1000000; // n의 최대범위
using namespace std;

vector<int> getPrimes(vector<bool> &is_prime)
{
    vector<int> primes;
    // 에라토스테네스의 체
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= sqrt(MAX); i++)
    {
        if (is_prime[i])
        {
            primes.push_back(i);
            for (int j = i * i; j <= MAX; j += i)
            {
                is_prime[j] = false;
            }
        }
    }
    return primes;
}

int goldbach(int n, vector<int> &primes, vector<bool> &is_prime)
{
    // 소수 2 제외
    for (int i = 1; i < primes.size(); i++)
    {
        if (is_prime[n - primes[i]])
            return primes[i];
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, answer;
    vector<bool> is_prime(MAX + 1, true);

    // 1M까지의 소수 array
    vector<int> primes = getPrimes(is_prime);

    while (true)
    {
        cin >> n;
        if (n == 0)
        {
            break;
        }

        //
        answer = goldbach(n, primes, is_prime);

        if (answer)
        {
            cout << n << " = " << answer << " + " << n - answer << '\n';
        }
    }
}