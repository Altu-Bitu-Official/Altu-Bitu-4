#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1000000;

vector<int> findPrime()
{
    vector<int> is_prime(MAX + 1, 1); // 소수 여부 저장

    for (int i = 2; i * i <= MAX; i++)
    {
        if (is_prime[i] != 1)
        { // 이미 지워진 수이면 탐색 X
            continue;
        }
        for (int j = i * i; j <= MAX; j += i)
        {
            if (is_prime[j] != 1)
            { // 이미 지워진 수이면 탐색 X
                continue;
            }

            is_prime[j] = 0; // 현재 수 지우기
        }
    }
    return is_prime;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int b;
    int n = 1;
    vector<int> is_prime = findPrime();
    while (n)
    {   
        int a=0;
        cin >> n;
        if (n == 0)
        {
            break;
        }

        if (n % 2 != 0 || n < 6)
        {
            continue;
        }
        for (int i = 3; i <= n / 2; i += 2) // 소수이면서 짝수인 것은 2밖에 없으므로 3부터 세면 전부 홀수
        {
            if (is_prime[i] == 1 && is_prime[n - i] == 1)
            {
                a = i;
                b = n - a;
                cout << n << " = " << a << " + " << b << "\n";
                break;
            }
        }
        if (a == 0)
        {
            cout << "Goldbach's conjecture is wrong."
                 << "\n";
        }
    }
    return 0;
}
