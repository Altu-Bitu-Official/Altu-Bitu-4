#include <iostream>
using namespace std;

/* 
한수: 양의 정수 X의 각 자리 => 등차수열
n 입력, n보다 작거나 같은 한수의 개수 출력
*/

bool ishansoo(int n) {
    if (n < 100) {
        //100이하인 경우: 전부 한수
        return true;
    }
    else {
        //n은 1000 이하의 자연수
        int n1 = n / 100;
        int n2 = (n % 100) / 10;
        int n3 = n % 10;

        if ((n1 - n2) == (n2 - n3)) {
            return true;
        }
        else {
            return false;
        }
    }

}
int main() {
    int n; 
    int count = 0;
    //입력
    cin >> n;
    for (int i = 1; i <= n; i++) {
        if (ishansoo(i)) count++;
    }
    cout << count;

    return 0;
}