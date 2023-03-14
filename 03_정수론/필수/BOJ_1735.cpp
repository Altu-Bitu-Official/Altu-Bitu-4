#include <iostream>

using namespace std;

// 최소공약수를 구하는 함수 (a > b)
int getGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcd(b, a%b);

}

int main() {
    int numer_a, deno_a, numer_b, deno_b, numer_new, deno_new, gcd; // numerator : 분자, denominator : 분모

    cin >> numer_a >> deno_a >> numer_b >> deno_b;

    gcd = getGcd(max(deno_a, deno_b), min(deno_a, deno_b));

    // 새로운 분수의 분자와 분모
    numer_new = numer_a * (deno_b / gcd) + numer_b * (deno_a / gcd);    
    deno_new = deno_a * deno_b / gcd;
    
    // 새로운 분자와 분모의 최대공약수로 각 수를 나눠줌으로써 기약분수로 만듬.
    cout << numer_new / getGcd(deno_new, numer_new) << ' ' << deno_new / getGcd(deno_new, numer_new);
}