#include <iostream>

using namespace std;

int isOdd(int num) {
    if(num%2==1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n, tmp, sum=0, odd=0;
    cin >> n;

    for(int i=0; i<n; i++) {
        cin >> tmp;
        sum+=tmp;
        odd+=isOdd(tmp);
    }

    if(sum%3!=0 || odd>sum/3) {
        cout << "NO";
    } else {
        cout << "YES";
    }

    return 0;
}