/**/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binarySearch(int left, int right, vector<int>&snack, int m)
{
    while(left<= right)
    {
    int mid = (left+right) /2;
    int cnt=0;
    for(int i=0;i<snack.size();i++)
    {
        cnt+=snack[i]/mid;
    }
    if(cnt >= m)
    {
        left = mid + 1;
    }
    else
    {
        right = mid -1;
    }
    }

    return left-1;
}
int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> snack(n);

    for(int i=0;i<n;i++)
    {
        cin >> snack[i];
    }
    sort(snack.begin(), snack.end());

    cout << binarySearch(1, snack[n-1], snack , m);
    return 0;
}