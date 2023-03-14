#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int getGcd(int a, int b) {
    while(b!=0) {
        a%=b;
        swap(a,b);
    }

    return a;
}

set<int> getFactors(int gcd) {
    set<int> factors;

    for(int i=2; i*i<=gcd; i++) {
        if(gcd%i==0) {
            factors.insert(i);
            factors.insert(gcd/i);
        }
    }
    factors.insert(gcd);

    return factors;
}

int main() {
    int n;
    int tmp;

    cin >> n;

    vector<int> nums(n);
    set<int> factors;

    for(int i=0; i<n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());

    //나머지가 같으므로 두 원소 차이를 M으로 나눴을 때 나누어 떨어짐
    //인접한 원소 차이들의 최대 공약수 구하기

    //최대공약수 구하기 전이니까 0번 1번 차이 변수에 저장
    tmp = nums[1]-nums[0];

    for(int i=2; i<n; i++) {
        //전 단계에서 구한 최대공약수와 두 원소 차이로 다시 최대공약수 구해서 갱신
        tmp = getGcd(max(tmp, nums[i]-nums[i-1]), min(tmp, nums[i]-nums[i-1]));
    }

    //구한 최대공약수의 약수 구하기
    factors = getFactors(tmp);

    for(int num : factors) {
        cout << num << " ";
    }

    return 0;
}