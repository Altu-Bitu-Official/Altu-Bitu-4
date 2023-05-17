// 세 용액

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void mixLiq(int n, vector<long long> &liq){
    long long zsum = 3*1e9 + 1;
    vector<int> idx(3,0); // 최종적으로 합이 0에 가깝게 하는 용액
    
    for (int start = 0; start < n-2; start++){ // 시작점 고정
        int mid = start+1, end = n-1;
        while (mid < end){
            long long csum = liq[start] + liq[mid] + liq[end]; // 현재 세 용액의 합
            if (abs(csum) <= zsum){
                zsum = abs(csum); // zsum 갱신
                idx = {start, mid, end}; // 인덱스 갱신
            }
            if (csum < 0){ // csum이 음수
                mid++; // 더 큰 값 만들기
            }
            else if (csum > 0){ // csum이 양수
                end--; // 더 작은 값 만들기
            }
            else{ // csum이 0이면 바로 종료
                cout << liq[idx[0]] << " "<< liq[idx[1]] << " " << liq[idx[2]];
                return;
            }
        }
    }
    cout << liq[idx[0]] << " "<< liq[idx[1]] << " " << liq[idx[2]];
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<long long> liq(n,0);
    
    for (int i = 0; i < n; i++){
        cin >> liq[i];
    }
    sort(liq.begin(), liq.end());
    mixLiq(n, liq);
    return 0;
}