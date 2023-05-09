// 입국심사

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long findNum(long long i, long long n, long long m, vector<int> &t){
    // i분 걸릴 때 심사가능한 사람 수
    long long cnt = 0; 
    for (int j = 0; j < n; j++){
        cnt += (i / t[j]);
    }
    return cnt;
}

long long binarySearch(long long n, long long m, vector<int> &t){ // 최소값을 반환해야 함
    long long idx_1 = 1; 
    long long idx_2 = *max_element(t.begin(), t.end()) * m / n; // 탐색 인덱스
    while (idx_1 <= idx_2){
        long long mid = (idx_1 + idx_2) / 2;
        if (findNum(mid, n, m, t) >= m){ // 심사한 사람 수가 m보다 많으면
            idx_2 = mid - 1;
        }
        else{
            idx_1 = mid + 1;
        }
    }
    return idx_1;
}

int main(){
    long long m, n;
    cin >> n >> m;
    vector<int> t(n, 0);
    
    for (int i = 0; i < n; i++){
        cin >> t[i];
    }
    cout << binarySearch(n, m, t);
    return 0;
}