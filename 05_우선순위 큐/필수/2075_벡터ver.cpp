// N번째 큰 수 - 벡터 이용 (메모리 초과)

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
    
    int n, x;
    vector<int> arr;
    cin >> n;
    int iter = n*n;
    
    while ((iter)--){
        cin >> x;
        arr.push_back(x);
    }
    partial_sort(arr.begin(), arr.begin() + n, arr.end(), greater<>()); // 부분 정렬
    
    cout << arr[n-1];
    return 0;
}