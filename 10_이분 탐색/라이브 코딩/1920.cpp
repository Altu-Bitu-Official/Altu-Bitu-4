#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
/*
* 이분탐색을 이용해 입력으로 주어진 키 값의 존재 여부를 구합니다
*/

int binarySearch(int n, int key, vector<int> &nums) {
    int left = 0; 
    int right = n - 1;
    int mid;
    // 키 값의 존재여부 구하기
    while (left <= right) {
        mid = (left + right) / 2;
        if (nums[mid] == key) {   // key 값이 배열의 중앙값과 같을 때
            return 1;
        }
        else if (nums[mid] > key) { // key 값이 배열의 중앙값보다 작을 때-> 더 작은 값 탐색
            right = mid - 1;
        }
        else {  // key 값이 배열의 중앙값보다 클때-> 더 큰 값 탐색
            left = mid + 1;
        }
    }
    return 0;
}

int main(void) {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m, key;
    // 입력
    cin >> n;
    vector<int> nums(n); // 자연수의 최대 개수가 100000이므로 해당 크기의 배열을 만들기
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());   // quick sort를 이용해 배열 오름차순으로 정렬
    // 입력
    cin >> m;
    while(m--) {
        cin >> key;
        // 연산 & 출력
        cout << binarySearch(n, key, nums) << '\n';
    }
    return 0;
}
