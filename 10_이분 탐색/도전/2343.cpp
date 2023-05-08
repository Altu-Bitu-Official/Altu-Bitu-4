// 기타 레슨

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findSize(int i, int n, int m, vector<int> &lec){
    // 크기가 i일 때 필요한 블루레이 수
    int sum = 0;
    int cnt = 1; 
    for (int j = 0; j < n; j++){
        sum += lec[j];
        if (sum > i){ // 용량 초과
            cnt++;
            sum = lec[j];
        }
    }
    return cnt;
}

int binarySearch(int n, int m, vector<int> &lec){ // 최소값을 반환해야 함
    int idx_1 = *max_element(lec.begin(), lec.end()); 
    int idx_2 = 1000000000; // 탐색 인덱스
    while (idx_1 <= idx_2){
        int mid = (idx_1 + idx_2) / 2;
        if (findSize(mid, n, m, lec) > m){ // 필요한 블루레이 개수가 m보다 크면
            idx_1 = mid + 1;
        }
        else{
            idx_2 = mid - 1;
        }
    }
    return idx_1;
}

int main(){
    int m, n;
    cin >> n >> m;
    vector<int> lec(n, 0);
    
    for (int i = 0; i < n; i++){
        cin >> lec[i];
    }
    cout << binarySearch(n, m, lec);
    return 0;
}