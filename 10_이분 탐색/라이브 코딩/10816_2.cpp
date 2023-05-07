// 숫자 카드 2

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binarySearch(vector<int> &an, int x, int n){
    int idx_1 = 0, idx_2 = n-1, mid; // 탐색 시작 인덱스, 끝 인덱스, 카드 개수
    bool notZero = false;
    while (idx_1 <= idx_2){
        mid = (idx_1 + idx_2) / 2;
        if (an[mid] == x){
            notZero = true;
            break;
        }
        else if (x < an[mid]){
            idx_2 = mid - 1;
        }
        else{
            idx_1 = mid + 1;
        }
    }
    // 인덱스를 한칸씩 움직이며 찾으므로 시간초과 발생
    if (notZero){
        idx_1 = mid - 1;
        idx_2 = mid + 1;
        while (an[idx_1] == x){
            idx_1--;
        }
        while (an[idx_2] == x){
            idx_2++;
        }
        cnt = idx_2 - idx_1 - 1;
    }
    return cnt;
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
        cout << binarySearch(an, x, n) << ' ';
    }
    return 0;
}