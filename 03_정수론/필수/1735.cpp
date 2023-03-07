#include <iostream>

using namespace std;

int findGCD(int m, int n) {
    while (n) {
        m %= n;
        swap(m, n);
    }
    return m;
}

int main() {
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;

    int m = b * d;
    int n = a * d + b * c;

    int gcd = findGCD(m, n);

    if (gcd != 1) {
        m /= gcd;
        n /= gcd;
    }
    cout << n << " " << m;

    return 0;
}