#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getSum(string num) {
    int sum=0;

    for(int i=0; i<num.length(); i++) {
        if (isdigit(num[i])) {
            sum+=num[i]-'0';
        }
    }
    return sum;
}

bool cmpNums(string num1, string num2) {
    if (num1.length()!=num2.length()) {
        return num1.length() < num2.length();
    }
    if (getSum(num1)!=getSum(num2)) {
        return getSum(num1) < getSum(num2);
    }
    return num1<num2;
}

int main() {
    int n;
    cin >> n;

    vector<string> nums(n);
    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end(), cmpNums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << '\n';
    }

    return 0;
}