#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
/*
* lower bound, upper bound를 구한 뒤, 둘의 차이를 구해주면 됩니다.
*/

//lower bound
int lowerBound(int left, int right, int target, vector<int>& arr) {
    while (left <= right) { 
        int mid = (left + right) / 2; 
        // 중간값이 target보다 크다면 target은 왼쪽에 있음
        // 중간값이 target과 같다면 왼쪽에 target과 같은 값이 더 있을 수 있음
        if (arr[mid] >= target) {
            right = mid - 1;
        }
        else { // 중간값이 target보다 작다면 target은 오른쪽에 있음
            left = mid + 1;
        }
    }
    /*
     * left를 리턴하는 이유
     * break 조건: left 포인터가 right 포인터보다 뒤에 있는 경우
     *    arr[mid] <= target일 때, left 포인터가 이동하고 break
     * 이 때 left값은 target이 되는 첫 지점 즉 lower bound임
     */
    return left;
}

//upper bound
int upperBound(int left, int right, int target, vector<int>& arr) {
    while (left <= right) { 
        int mid = (left + right) / 2; 
        // 중간값이 target보다 작다면 target은 오른쪽에 있음
        // 중간값이 target과 같다면 오른쪽에 target과 같은 값이 더 있을 수 있음
        if (arr[mid] <= target) {
            left = mid + 1;
        }
        else { // 중간값이 target보다 크다면 target은 왼쪽에 있음
            right = mid - 1;
        }
    }
    /**
     * left를 리턴하는 이유
     * break 조건: left 포인터가 right 포인터보다 뒤에 있는 경우
     *    arr[mid] == target 일 때 left가 target을 초과하는 순간 break
     * 이 때의 left 값이 upper bound
     */
    return left;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, input;

    //입력
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    //이분 탐색을 하기 위해 정렬
    sort(arr.begin(), arr.end());

    //입력
    cin >> m;
    while (m--) {
        cin >> input;
        //연산 & 출력
        cout << upperBound(0, n - 1, input, arr) - lowerBound(0, n - 1, input, arr) << ' ';
    }
    return 0;
}