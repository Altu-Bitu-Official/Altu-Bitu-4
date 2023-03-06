#include <iostream>
#include <vector>

using namespace std;

int getGcd(int a, int b) {
    while(b!=0) {
        a%=b;
        swap(a,b);
    }

    return a;
}

int main() {
    int numer, denom;
    int numer1, denom1;
    int numer2, denom2;
    int gcd;

    cin >> numer1 >> denom1;
    cin >> numer2 >> denom2;

    numer=numer1*denom2+numer2*denom1;
    denom=denom1*denom2;

    gcd = getGcd(max(numer, denom), min(numer, denom));

    cout << numer/gcd << " " << denom/gcd;

    return 0;
}