#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;

    /*vector<char> v(n);
    fill(v.begin(), v.end(), '?');
    이렇게 말고 벡터를 선언하면서 바로 특정 값으로 초기화 가능*/

    vector<char> v(n,'?');


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
            } // 이중반복문은 O(n^2)의 시간복잡도를 가지므로 배열을 선언해서 풀어주면 더 좋다

    for (int i=0; i<n; i++) {
        cout << v[(i + idx) % n];
    }
    cout << "\n";
    return 0;

}