#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int lowerBound(int left, int right, int target, vector<int>& arr) {
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] >= target)  right = mid - 1;
        else left = mid + 1;   
    }
    return left;
}

int upperBound(int left, int right, int target, vector<int>& arr) {
    while (left <= right) {
        int mid = (left + right) / 2;
       
        if (arr[mid] <= target) left = mid + 1;
        else  right = mid - 1;
    }
    return left;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, input;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    cin >> m;
    while (m--) {
        cin >> input;
        if (upperBound(0, n - 1, input, arr) - lowerBound(0, n - 1, input, arr) > 0) {
            cout << "1" << " ";}
        else cout << "0" << " ";
    }
    return 0;
}