#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int gcdIter(int a, int b) {
    while(b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

vector<int> getCD(vector<int> nums) { // 공약수를 저장한 벡터 리턴하는 함수
    vector<int> result;
    // 먼저 모든 수의 최대공약수 구하기
    int num = nums[0];
    for(int i = 1; i < nums.size(); i++) {
        num = gcdIter(max(num, nums[i]), min(num, nums[i]));
    }

    // 공약수 구하기: 공약수는 최대공약수의 약수
    for(int i = 1; i <= num; i++) {
        if(num % i == 0) {
            result.push_back(i);
        }
    }
    return result;
}

vector<int> findM(vector<int> nums) { // m에 해당하는 수 집합 리턴하는 함수
    vector<int> m;
    vector<int> temp(nums.size());
    int min = *min_element(nums.begin(), nums.end());
    for(int i = 0; i < min - 1; i++) { // min의 나머지는 0 ~ min-2이 될 수 있음 (1보다 큰 나머지)
        for(int j = 0; j < nums.size(); j++) { // 벡터 안의 각 수마다
            temp[j] = nums[j] - i;             // 나머지만큼 빼고
        }
        
        temp = getCD(temp);                    // 벡터의 공약수 구하기
        if(temp.size() != 0) { 
            m.insert(m.end(), temp.begin(), temp.end()); // 두 벡터 연결
        }
    }
    // 중복 요소 제거
    sort(m.begin(), m.end());
    m.erase(unique(m.begin(), m.end()), m.end());

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

    vector<int> m = findM(nums);

    for(int i = 0; i < m.size(); i++) {
        cout << m[i] << " ";
    }

    return 0;
}