// N번째 큰 수 - 배열 이용

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{   
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int arr[n*n];
    
    for(int i=0; i<n*n; i++)
        cin >> arr[i];

    partial_sort(arr, arr + n, arr+n*n, greater<>()); // 부분 정렬
    
    cout << arr[n-1];
    return 0;
}