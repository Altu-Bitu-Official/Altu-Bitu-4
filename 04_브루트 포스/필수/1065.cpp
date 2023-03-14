#include <iostream>

using namespace std;

int countNum(int &n) {
    int num = 0;
    while (n > 100) {
        int d1 = n / 100 - (n % 100) / 10;
        int d2 = (n % 100) / 10 - n % 10;
        if (d1 == d2) {
            num++;
        }
        n--;
    }
    num += 99;

    return num;
}

int main() {
    int n;
    cin >> n;

    int num = 1;

    if (n < 100) {
        cout << n;
    } else{
        cout << countNum(n);
    }

    return 0;
}