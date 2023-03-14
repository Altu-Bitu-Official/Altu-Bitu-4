#include <iostream>

using namespace std;

int gcdIter(int b, int d){
    while(d != 0){
        b %= d;
        swap(b,d);
    }
    return b;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c, d;
    int top, bottom;
    int gcd;
    cin >> a >> b;
    cin >> c >> d;

    bottom=b*d;
    top = a*d + b*c;
    gcd = gcdIter(top, bottom);
    bottom /= gcd;
    top /= gcd;

    cout << top << " " << bottom;

    return 0;
}
