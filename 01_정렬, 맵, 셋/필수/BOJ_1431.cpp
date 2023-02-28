#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string serial;

bool cmp(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) {
        return s1.length() < s2.length();
    }
    int num1 = 0, num2 = 0;
    for (int i = 0; i<s1.length(); i++) {
        if (s1[i] >= '0' && s1[i] <= '9') {
            num1 += s1[i] - '0';
        }
        if (s2[i] >= '0' && s2[i] <= '9') {
            num2 += s2[i] - '0';
        }
    }
    if (num1 != num2) {
        return num1 < num2;
    }
    return s1 < s2;
}

int main() {
    int n;
    string serial[50] = {};

    //입력
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> serial[i];
    }
    //연산
    sort(serial, serial + n, cmp);
    //출력
    for (int i = 0; i < n; i++) {
        cout << serial[i] << '\n';
    }
    return 0;
}