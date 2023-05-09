#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(int n, int key, int nums[])
{
    int left = 0, right = n - 1; // 범위를 줄여줄 각각의 인덱스
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (nums[mid] == key)
        {
            return 1;
        }
        else if (nums[mid] < key)
        { // mid보다 key가 크면 left의 범위를 줄이자
            left = mid + 1;
        }
        else
        { // mid보다 key가 작으면 right의 범위를 줄이자
            right = mid - 1;
        }
    }
    return 0; // 찾지 못하면 0 반환
}
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m;         // 주어지는 정수개수n, 찾는 정수 개수m
    int nums[100001]; // 주어지는 정수열
    int key;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    sort(nums, nums + n); // sort function +
    cin >> m;
    while (m--)
    {
        cin >> key;
        cout << binarySearch(n, key, nums) << '\n';
    }
}