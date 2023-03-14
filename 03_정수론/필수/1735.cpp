#include <iostream>
#include <algorithm>

using namespace std;

int getGcd(int a, int b){
    //a와 b의 gcd = a%b와 b의 gcd
    if(b == 0){
        return a;
    }
    return getGcd(b, a%b);
}

int main()
{
    int a, b, n, m;
    //입력
    cin >> a >> b;  //기약분수 : a/b
    cin >> n >> m;  //기약분수 : n/m

    //분모 구하기
    int denominator = b*m;
    //분자 구하기
    int numerator = a*m + b*n;

    //분모와 분자의 최소공약수로 약분하기
    int gcd = getGcd(max(denominator, numerator), min(denominator, numerator));
    denominator /= gcd;
    numerator /= gcd;

    //출력
    cout << numerator << " " << denominator;
}