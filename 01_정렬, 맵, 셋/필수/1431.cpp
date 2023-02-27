#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getSum(const string& s){
    int sum = 0;
    for (char i : s) {
        if (i >= 48 && i <= 57) {
            sum += i - 48;
        }
    }
    return sum;
}

bool comp(string &s1, string &s2) {

    if (s1.length() != s2.length()) {
        return s1.length() < s2.length();
    }

    int sum1 = getSum(s1);
    int sum2 = getSum(s2);
    if (sum1 != sum2) {
        return sum1 < sum2;
    }

    return s1 < s2;
}

int main() {
    int n;
    cin >> n;

    vector<string> v;

    // 입력
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), comp);

    // 출력
    for (int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }

    return 0;
}