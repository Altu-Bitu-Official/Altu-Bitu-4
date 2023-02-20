#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(string s1, string s2){
    int sum1 = 0, sum2 = 0;
    if (s1.length() != s2.length()) {
        if (s1.length() < s2.length()) return s1 < s2;
    }
    for (int i = 0; i < s1. length(); i++) {
        if (isdigit(s1[i])) sum1+= s1[i] - '0';
        if (isdigit(s2[i])) sum2+= s2[i] - '0';
    }
    if (sum1 != sum2) {
        if (sum1 < sum2) return s1 < s2;
    }
    return s1 < s2;
}


int main() {
    int n;
    string temp;
    cin >> n;
    vector<string> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end(), comp);

    for (int i = 0; i < n; i++) cout << arr[i] << '\n';
}