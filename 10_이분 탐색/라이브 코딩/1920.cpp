// 수 찾기

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> &an, int x, int n){
    int idx_1 = 0, idx_2 = n-1;
    
    while (idx_1 <= idx_2){
        int mid = (idx_1 + idx_2) / 2;
        if (an[mid] == x){
         return 1;
        }
        else if (x < an[mid]){
            idx_2 = mid - 1;
        }
        else{
            idx_1 = mid + 1;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, x;
    cin >> n;
    vector<int> an(n,0);
    for (int i=0; i<n; i++){
        cin >> an[i];
    }
    sort(an.begin(), an.end());
    cin >> m;
    while (m--){
        cin >> x;
        cout << binarySearch(an, x, n) << '\n';
    }
    return 0;
}