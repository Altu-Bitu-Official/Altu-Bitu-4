#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    long long input;
    cin >> n;
    vector<int> a(n);
    for (int i = n - 1; i >= 0; i--)
    {
        cin >> input;
        a[i] = input;
    }
    long long res = a[0];
    for (int i = 1; i < n; i++)
    {
        if (res <= a[i])
        {
            res = a[i];
        }
        else
        {
            if ((res % a[i]) != 0)
            {
                res = (res / a[i] + 1) * a[i];
            }
            else
            {
                res = (res / a[i]) * a[i];
            }
        }
    }
    cout << res;
    return 0;
}