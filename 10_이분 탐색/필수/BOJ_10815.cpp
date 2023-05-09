#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int binarySearch(int n, int key, vector<int> &nums)
{
    int left = 0;
    int right = n - 1;
    int mid;
    // 키 값의 존재여부 구하기
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] == key)
        { // key 값이 배열의 중앙값과 같을 때
            return 1;
        }
        else if (nums[mid] > key)
        { // key 값이 배열의 중앙값보다 작으면 right를 줄여 더 작은 값에서 찾음
            right = mid - 1;
        }
        else
        { // key 값이 배열의 중앙값보다 크면 left를 늘려 더 큰 값에서 찾음
            left = mid + 1;
        }
    }
    return 0;
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL); // 시간단축

    int n, m, key;
    cin >> n;            // 주어진 정수의 개수
    vector<int> nums(n); // 주어진 정수의 vector
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end()); // nums벡터를 오름차순으로 정렬
    cin >> m;                       // 찾을 정수의 개수
    while (m--)
    {
        cin >> key;                                 // 찾을 값을 찾아
        cout << binarySearch(n, key, nums) << '\n'; // 존재하면 1, 존재하지않으면 0
    }
    return 0;
}