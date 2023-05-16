#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int  cnt[100001];

int twoPointer(vector<int> &longLength, int n, int k)
{
    int left = 0, right = 0;
    int ans = 0;
    while (right < n &&left <= right)
    {
        cnt[longLength[right]]++;  //cnt[현재 right위치의 값]을 1증가시킴
        while (cnt[longLength[right]] > k) // k값을 넘어서면
        {
            cnt[longLength[left]]--; //cnt[현재 left위치의 값]을 1감소시킴
            left++; //오른쪽으로 이동
        }

        ans = max(ans, right-left+1); //최장연속부분수열의 길이
        right++;
    }
    return ans;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    vector<int> longlength;
    cin >> n >> k;
    longlength.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> longlength[i];
    }

    cout << twoPointer(longlength, n, k);
    return 0;
}