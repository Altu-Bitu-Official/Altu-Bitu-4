// 숫자 카드 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// x의 시작 전 위치
int lowerBound(vector<int> &an, int x, int n){
    int idx_1 = 0, idx_2 = n-1, cnt = 0, mid;
    while (idx_1 <= idx_2){
        mid = (idx_1 + idx_2) / 2;
        // 중간값이 target과 같다면 왼쪽에 target과 같은 값이 더 있을 수 있음
        if (an[mid] >= x){
            idx_2 = mid - 1;
        }
        else{ // 중간값이 target보다 작다면 target은 오른쪽에 있음
            idx_1 = mid + 1;
        }
    }
    return idx_1;
}

// x의 마지막 위치
int upperBound(vector<int> &an, int x, int n){
    int idx_1 = 0, idx_2 = n-1, cnt = 0, mid;
    while (idx_1 <= idx_2){
        mid = (idx_1 + idx_2) / 2;
        // 중간값이 target과 같다면 오른쪽에 target과 같은 값이 더 있을 수 있음
        if (an[mid] <= x){
            idx_1 = mid + 1;
        }
        else{ // 중간값이 target보다 작다면 target은 오른쪽에 있음
            idx_2 = mid - 1;
        }
    }
    return idx_1;
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
        cout << upperBound(an, x, n) - lowerBound(an, x, n) << ' ';
    }
    return 0;
}