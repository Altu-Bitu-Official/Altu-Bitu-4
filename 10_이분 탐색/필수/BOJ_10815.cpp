/**/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(int n, int key, vector<int>&nums)
{
    int left = 0;
    int right = n-1;
    int mid;

    while(left <= right)
    {
        mid = (left+right)/2;
        if(nums[mid] == key)
        {
            return 1;
        }
        else if (nums[mid]<key)
        {
            left = mid + 1;
        }
        else 
        {
            right = mid -1;
        }
        
    }
    return 0;
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(NULL);

    int n, m, key;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n;i++)
    {
        cin >> nums[i];
    }
    sort(nums.begin(),nums.end());
    
    cin >> m;
    while (m--)
    {
        cin>> key;
        cout << binarySearch(n, key, nums) << " ";
    }
    return 0;
}