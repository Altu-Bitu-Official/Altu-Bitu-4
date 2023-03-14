#include <iostream>

using namespace std;
void hansoo(int x) {
    int num = 99;
    int count = 0;
    if (x < 100) {
        count = x;
    }
    else {
        for (num = 100; num <= x; num++) {
            if (num / (100) - ((num % 100) / 10) == ((num % 100) / 10) - num % 10) {
                count++;
            }
        }
        count = count + 99;
    }
    cout << count;
}

int main()
{
    int n;
    cin >> n;
    hansoo(n);


    return 0;
}