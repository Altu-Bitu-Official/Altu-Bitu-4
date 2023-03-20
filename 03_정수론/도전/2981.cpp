#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int getGcdRecur(int a, int b) {
    if(b == 0) {
        return a;
    }
    return getGcdRecur(b, a % b);
}

vector<int> findM(vector<int> &nums) { // m에 해당하는 수 집합 리턴하는 함수
    vector<int> m;

    // 두 수 사이 간격의 최대공약수 구하기
    int gcd = nums[1] - nums[0];
    for(int i = 2; i < nums.size(); i++) {
        gcd = getGcdRecur(max(gcd, nums[i] - nums[i-1]), min(gcd, nums[i] - nums[i-1]));
    }

    // 공약수 구하기: 공약수는 최대공약수의 약수
    for(int i = 2; i <= gcd/2; i++) {
        if(gcd % i == 0) {
            m.push_back(i);
        }
    }
    m.push_back(gcd);

    return m;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
    vector<int> m = findM(nums);

    for(int i : m) {
        cout << i << " ";
    }

    return 0;
}