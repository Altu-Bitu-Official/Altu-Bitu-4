#include <iostream>

using namespace std;

int gcd(int x, int y)
{ // x와 y의 최대공약수를 구하는 함수
    while (y)
    {           // y가 0이면 x가 gcd
        x %= y; // GCD(a,b) == GCD(a%b, b)
        swap(x, y);
    }
    return x;
}

int main()
{
    int a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;

    int e, f; // 기약분수꼴로 만들기 이전의 분자,분모
    e = a * d + b * c;
    f = b * d;

    int g = gcd(f, e);

    cout << e / g << ' ' << f / g;

    return 0;
}