// 10815 숫자 카드
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 이분탐색을 이용해 num 값이 n개의 원소를 가진 arr에 존재하는지 확인한다
// 존재하면 1, 존재하지 않으면 0을 반환한다
int binarySearch(int n, int num, vector<int> &arr) {
    int left = 0;
    int right = n-1;
    int mid;

    while (left <= right) {
        mid = (left + right) / 2;
        if (arr[mid] == num){   // num 이 배열의 중앙값과 같을 때 
            return 1;
        }
        else if(arr[mid] < num){    // num 이 배열의 중앙값보다 클 때
            left = mid + 1;
        }
        else{   // num 이 배열의 중앙값보다 작을 때
            right = mid - 1;
        }
    }
    return 0;
}

int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);

    int n, m, num;

    // 입력 : 
    cin >> n;
    vector<int> arr(n,0);
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    // 이분 탐색을 위해 배열을 quicksort를 이용해서 오름차순으로 정렬
    sort(arr.begin(), arr.end());

    // 입력 : 
    cin >> m;
    while (m--){
        cin >> num;
        // 연산 및 출력
        cout << binarySearch(n, num, arr) << " ";
    }

    return 0;
}