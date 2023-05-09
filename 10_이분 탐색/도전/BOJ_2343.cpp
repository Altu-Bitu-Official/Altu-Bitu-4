#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bdCnt(long long t, vector<int>& arr) {
    int cnt = 1;
    long long n = t;

    for (int i : arr) {
        if (i > t) {
            return 100000;
        }
        if (i > n) {
            cnt++;
            n = t;
        }
        n -= i;
    }
    return cnt;
}

int binarySearch (int left, long long right, int target, vector<int>& arr) {
    long long mid;

    while (left <= right) {
        mid = (left + right) / 2;
        int cnt = bdCnt(mid, arr);

        if (cnt <= target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return left;

}

int main() {
    int n, m;
    long long sum = 0;
    vector<int> arr;
    cin >> n >> m;
    arr.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }


    cout << binarySearch(sum / m, sum, m, arr);



}