#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int binarySearch(int n, int m, vector<int> &arr){
    int left = 1;
    int right = arr[n-1];
    int mid;
    int result = 0;
    
    while(left <= right){
        int cnt = 0;
        mid = (left + right) / 2; //중앙값

        for (int i = 0; i < n; i++) {
			cnt += arr[i] / mid; //mid 과자 길이로 나눠줄 수 있는 양
		}
        if (cnt < m) { //과자 나눠줄 수 없을 때 
			right = mid - 1;
		}
		else{ //과자 나눠줄 수 있을 때
			left = mid + 1;
			result = mid;
		}
    }
    return result;
    
}

int main()
{
    //입력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int m, n;
    cin >> m >> n;
    
    vector<int> arr(n, 0);
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    //이분 탐색을 하기 위해 정렬
    sort(arr.begin(), arr.end());
    
    //출력 
    cout << binarySearch(n, m, arr) << endl;
    

    return 0;
    
    
}
