#include <iostream>
#include <vector>

using namespace std;

// 최대공약수를 구하는 함수
int getGCD(int a, int b) {
    while(b) {
        a %= b;     // 유클리드 호제법 사용
        swap(a, b); // b가 a보다 커졌으므로 둘이 바꿈
    }
    return a; 
}

// 분자를 구하는 함수
int getX(vector<int> nums, int gcd) {
    return (nums[0] * nums[3] + nums[2] * nums[1]) / gcd;
}

// 분모를 구하는 함수
int getY(vector<int> nums, int gcd) {
    return nums[1] * nums[3] / gcd;
}

int main() {
    // 입출력 속도 향상 코드
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> nums;
    int input;
    for(int i = 0; i < 4; i++) {  
        cin >> input;
        nums.push_back(input);
    }

    int gcd = getGCD(max(nums[1], nums[3]), min(nums[1], nums[3])); // 최대공약수
    int x = getX(nums, gcd);  // 분자
    int y = getY(nums, gcd);  // 분모: 최소공배수

    int resultGCD = getGCD(y, x);
    x /= resultGCD;
    y /= resultGCD;

    cout << x << " " << y;

    return 0;
}
