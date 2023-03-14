#include <iostream>
using namespace std;

int gcd(int a, int b) {
    //반복문 최대공약수(gcd) 구하기
    int tmp;
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    return a;
}

int main() {
    //입력
    int a1, a2;
    int b1, b2;
    int c1, c2;
    cin >> a1 >> a2;
    cin >> b1 >> b2;
    
    c1 = a1 * b2 + a2 * b1; // 분자
    c2 = a2 * b2; // 분모

    //출력
    int min = gcd(c1, c2);
    cout << c1 / min << " " << c2 / min;
    return 0;
}