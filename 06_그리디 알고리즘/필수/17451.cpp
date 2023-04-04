#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    vector<int> v;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        v.push_back(num);
    }
    long speed = v[n - 1];

    for (int i = n - 1; i >= 0; i--) {
        if (v[i] > speed) {
            speed = v[i];
        } else if (v[i] < speed) {
            int t = 0;
            if (speed % v[i] != 0) {
                t = 1;
            }
            speed = v[i] * (speed / v[i] + t);
        }
    }

    cout << speed;
}