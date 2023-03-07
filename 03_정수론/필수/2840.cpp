#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    vector<char> v(n);
    fill(v.begin(), v.end(), '?'); //벡터 초기화

    int idx = 0;
    for (int i=0; i<k; i++) {
        int tmp;
        char c;

        cin >> tmp >> c;
        tmp %= n;

        if (idx - tmp < 0) {
            idx = (idx - tmp) + n;
        } else {
            idx -= tmp;
        }

        //한 인덱스에 다른 알파벳 들어가려고 할 때
        if (v[idx] != '?' && v[idx] != c) {
            cout << "!\n";
            return 0;
        } else {
            v[idx] = c;
        }
    }

    //중복 없는 조건
    for (int i=0; i<n; i++)
        for(int j=i+1; j<n; j++)
            if (v[i] != '?' && v[i] == v[j]){
                cout << "!\n";
                return 0;
            }

    for (int i=0; i<n; i++) {
        cout << v[(i + idx) % n];
    }
    cout << "\n";
    return 0;

}