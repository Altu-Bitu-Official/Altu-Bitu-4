// 키 순서 - 시간초과
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void findNum(int n, vector<set<int>> &height_low, vector<set<int>> &height_high){
    for (int i = 1; i <= n; i++){
        for (auto s : height_low[i]){ // i보다 작은 정점들에게 i보다 큰 정점들을 삽입
            height_high[s].insert(height_high[i].begin(), height_high[i].end());
        }
        for (auto s: height_high[i]){ // i보다 큰 정점들에게 i보다 작은 정점들을 삽입
            height_low[s].insert(height_low[i].begin(), height_low[i].end());
        }
    }
    int cnt = 0;
    for (int i = 1; i<=n; i++){
        if ((height_low[i].size() + height_high[i].size()) == n-1){
            cnt++;
        }
    }
    cout << cnt;
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    vector<set<int>> height_low(n+1);
    vector<set<int>> height_high(n+1);
    
    while (m--){
       cin >> a >> b;
       height_high[a].insert(b); // a보다 키가 큰 사람들 저장
       height_low[b].insert(a); // b보다 키가 작은 사람들 저장
    }
    findNum(n, height_low, height_high);
    return 0;
}