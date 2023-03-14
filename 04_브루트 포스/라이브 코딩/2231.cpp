#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i=1; i<n; i++) {
        int sum=i;
        int tmp=i;

        //숫자에 숫자 각 자리 수 합 더하기
        while(tmp>0) {
            sum+=(tmp%10);
            tmp/=10;
        }

        if(sum==n) {
            cout << i;
            return 0;
        }
    }

    cout << 0;

    return 0;
}