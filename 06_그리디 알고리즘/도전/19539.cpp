#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // 3*k = 2*k + 1*k임을 이용

    int n, h, k = 0, sum = 0;
    bool flag = false;
    cin >> n;
    while (n--)
    {
        cin >> h;

        // sum (==3*k) 만들기
        sum += h;

        // 2*k으로 표현되는 최대 k 구하기
        k += h / 2;
    }

    // 출력
    (sum % 3==0) && (sum / 3 <= k) ? cout << "YES" : cout << "NO";
}