#include <iostream>

using namespace std;

int getGcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int main() {
    int a1, a2, b1, b2;//첫번째분수의 분자, 분모, 두번째분수의 분자, 분모
    cin >> a1 >> a2 >> b1 >> b2;

    int temp1, temp2;//약분 하기 전 상태인 분수의 분자, 분모
    //약분하기 전 거대분수
    temp1 = a1 * b2 + a2 * b1;
    temp2 = a2 * b2;

    int factor = getGcd(temp1, temp2);//최대공약수
    int final1, final2;
    final1 = temp1 / factor;
    final2 = temp2 / factor;

    cout << final1 << " " << final2;




}