#include <iostream>

using namespace std;

int getGcd(int x, int y)
{
    if (x < y)
    {
        swap(x, y);
    }
    while (y != 0)
    {
        x %= y;
        swap(x, y);
    }
    return x;
}

int main()
{
    int a_num, a_denom, b_num, b_denom, num, denom, gcd;
    cin >> a_num >> a_denom >> b_num >> b_denom;

    num = a_denom * b_num + a_num * b_denom;
    denom = a_denom * b_denom;

    gcd = getGcd(num, denom);

    cout << num / gcd << ' ' << denom / gcd;
}