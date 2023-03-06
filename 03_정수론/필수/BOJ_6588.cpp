#include <iostream>
#include <cmath>
using namespace std;

#define MAX 1000000
int prime[MAX];

void is_prime()
{

    for (int i = 2; i * i <= MAX; i++)
    {

        if (prime[i] == 0)
        {

            for (int j = i * i; j <= MAX; j += i)
            {
                prime[j] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    is_prime();

    while (true)
    {
        bool flag = true;
        cin >> n;
        if (n == 0)
        {
            break;
        }

        for (int a = 3; a <= n; a += 2)
        {
            if (prime[a] == 0 && prime[n - a] == 0)
            {
                cout << n << " = " << a << " + " << n - a << "\n";
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }

    return 0;
}