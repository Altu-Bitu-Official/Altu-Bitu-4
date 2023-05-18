#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int cntRouter(int mid, vector<int>& houses)
{
    int cnt = 1;
    int cur = houses[0];

    for(int i=1 ; i<houses.size();i++)
    {
        if(houses[i]-cur >= mid)
        {
            cnt++;
            cur = houses[i];
        }
    }
    return cnt;
}

int binarySearch (int left, int right, int target, vector<int>&houses)
{
    while(left<=right)
    {
        int mid = (left + right)/ 2; //거리
        int installed = cntRouter(mid, houses); // 거리가 미드일때 설치할 수 있는 라우터의 수 

        if( installed < target) //거리 줄여야
        {
            right = mid -1;
        }
        else
        {
            left = mid+1; //거리 늘여야
        }
   
    }
    return left -1;
}
int main()
{
    int n,c;
    cin >> n >> c; // 집의 개수 , 공유기의 개수
    vector<int> houses(n,0);

    for(int i=0 ;i <n;i++)
    {
        cin >> houses[i];

    }

    sort(houses.begin(), houses.end()); // 1 2  4      8 9

    cout << binarySearch(1, houses[n-1]- houses[0], c, houses); // 거리 1, 9-1, c(3), houses 
    return 0;
}