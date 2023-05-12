// 두 용액

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef pair<int, int> pi;

void findZero(int n, vector<int> &liq){
    
    int low = 0, high = n-1; // 탐색 인덱스
    int min_val = abs(liq[low] + liq[high]);
    pi ans = {liq[low], liq[high]}; // min_val을 만드는 두 용액 값
    
    while (low < high){
       int val = liq[low] + liq[high];
        
       if (abs(val) < abs(min_val)){
           min_val = abs(val); // min_val 갱신
           ans = {liq[low], liq[high]};
       }
       if (val < 0){ // 현재 값이 0보다 작다면 더 큰 값을 만들어야 함
           low++;
       }
       else if (val > 0){ // 현재 값이 0보다 크다면 더 작은 값을 만들어야 함
           high--;
       }
       else{ // 0이면 stop
           break;
       }
    }
    cout << ans.first << " " << ans.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int n;
    
    cin >> n;
    vector<int> liq(n, 0); // 용액
    
    for (int i = 0; i<n; i++){
        cin >> liq[i];
    }
    sort(liq.begin(), liq.end());
    
    findZero(n, liq);
    
    return 0;
}