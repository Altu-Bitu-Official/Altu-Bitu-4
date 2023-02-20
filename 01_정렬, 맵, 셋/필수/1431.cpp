#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2) {
    if (s1.length() < s2.length()) {
        return true;
    } else if (s1.length() == s2.length()) {
        int sum1 = 0;
        int sum2 = 0;
        for (int i = 0; i < s1.length(); i++) {

            if (s1[i] >= 48 && s1[i] <= 57) {
                sum1 += s1[i] - 48;
            }
            if (s2[i] >= 48 && s2[i] <= 57) {
                sum2 += s2[i] - 48;
            }
        }
        if (sum1 < sum2) {
            return true;
        } else if (sum1 == sum2) {
            for (int i = 0; i < s1.length(); i++) {
                if ((int) s1[i] < (int) s2[i]) {
                    return true;
                } else if ((int) s1[i] > (int) s2[i]) {
                    return false;
                }
            }
        }
        return false;
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<string> v;

    // 입력
    // 왜 while(n--)로 입력받으면 제대로 작동하지 않는걸까요?
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