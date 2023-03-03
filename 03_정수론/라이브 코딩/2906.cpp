#include <iostream>

using namespace std;

int getGcd(int n, int m) {
    //유클리드 호제법
    while(m!=0) {
        n%=m;
        //나누면 첫번째 숫자가 두번째 숫자보다 작아지니까 위치 바꿔줌
        swap(n, m);
        //계속 반복
    }
    //나머지(=m) 0 될 때, 나누는 수(=n) 반환
    return n;
}

int main() {
    int n, m;

    cin >> n >> m;

    int gcd = getGcd(max(n,m), min(n,m));

    //최소공배수는 (n*m)/최대공약수
    cout << gcd << "\n" << n*m/gcd;

    return 0;
}