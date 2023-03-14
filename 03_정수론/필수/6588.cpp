#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<bool> isPrime(int n) {
    vector<bool> is_prime(n + 1, true);

    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> is_prime = isPrime(1000000);

    while (true) {
        int num, a = 0, b = 0;
        cin >> num;

        if (num == 0) {
            break;
        }

        for (int i = 0; i < is_prime.size(); i++) {
            if (is_prime[i]) {

                a = i;
                b = num - a;

                if (a > b) {
                    break;
                }

                if (!is_prime[b]) {
                    continue;
                } else {
                    break;
                }

            }
        }

        if (a != 0 && a > b) {
            cout << "Goldbach's conjecture is wrong.";
        } else {
            cout << num << " = " << a << " + " << b << "\n";
        }
    }

}