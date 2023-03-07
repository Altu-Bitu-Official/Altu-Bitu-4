#include <iostream>
#include <vector>
#include <cmath>
#include <set>

using namespace std;

#define MAX 5000000

// a > b
int getGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return getGcd(b, a%b);
}


int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> m(n), input(n);
    set<int> differences, answer;

    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    int idx = 0;
    for (int i = 0; i < n-1; i++) {
        differences.insert(abs(input[i] - input[i+1]));
    } // 인접하는 두 수의 차이를 셋에 저장

    int first_dif = *differences.begin(); // 가장 작은 차이

    for (auto iter = ++differences.begin(); iter != differences.end(); iter++) {
        first_dif = getGcd(*iter, first_dif);

    } // 차이의 끝까지 최대공약수를 구해서 가장 작은 최대공약수를 얻음.
    
    int a = first_dif;

    for (int i = 2; i*i <= a; i++) {
        if (a%i == 0) {
            answer.insert(i);
            answer.insert(a/i);
        }
    } // 최대공약수의 sqrt까지만 탐색하고, 구해진 약수를 최대굥약수로 나누어서 반대편 약수를 얻은 뒤 저장.

    for (auto iter = answer.begin(); iter != answer.end(); iter++) {
        cout << *iter << ' ';
    }

    cout << a;
    
    return 0;
}
