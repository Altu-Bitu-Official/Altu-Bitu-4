#include <iostream>
#include <algorithm>

using namespace std;
int gcdIter(int a, int b)
{

    while (b != 0)
    {
        /*int tmp = a % b;
        a = b;
        b = tmp;*/
        a %= b;
        swap(a, b);
    }
    return a;
}
int main()
{
    int a, b, c, d, molecule, denominator;
    cin >> a >> b >> c >> d;

    molecule = a * d + b * c;
    denominator = b * d;
    int gcd = gcdIter(max(molecule, denominator), min(molecule, denominator));

    molecule /= gcd;
    denominator /= gcd;
    cout << molecule << " " << denominator;
    return 0;
}