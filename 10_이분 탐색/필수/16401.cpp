// 과자 나눠주기

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// target 길이일 때 나누어 줄 수 있는 수
int sharingSnack(int target, vector<int> &ln){
    int cnt = 0;
    for (int i = 0; i<ln.size(); i++){
        cnt += (ln[i] / target);
    }
    return cnt;
}
// m명에게 나누어 줄 수 있는 최대 길이 탐색
int binarySearch(int idx_1, int idx_2, int m, vector<int> &ln){
    while (idx_1 <= idx_2){ 
        int mid = (idx_1 + idx_2) / 2;
        if (sharingSnack(mid, ln) >= m){ // m명 이상에게 나누어줄 수 있을 때
            idx_1 = mid + 1;
        }
        else{ // m명 미만에게 나누어줄 수 있을 때
            idx_2 = mid - 1;
        }
    }
    return idx_1 - 1;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> ln(n,0);
    
    for (int i=0; i<n; i++){
        cin >> ln[i];
    }
    sort(ln.begin(), ln.end());
    
    // 탐색 길이 : 1~막대 길이의 최댓값
    cout << binarySearch(1, ln[n-1], m, ln);
    return 0;
}