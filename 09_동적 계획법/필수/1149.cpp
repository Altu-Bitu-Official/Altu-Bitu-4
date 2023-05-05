#include <iostream>
#include <vector>

using namespace std;

vector<int> r, g, b;

int findMinCost(int n) {
    // r[i]: i번째 집을 빨간색으로 칠했을 때 비용의 최솟값

    // 현재 집을 red로 칠하려면 이전 집이 green이나 blue여야 함. 둘 중 더 작은 비용으로 설정
    for (int i = 1; i < n; i++) {
        r[i] += min(g[i-1], b[i-1]); 
        g[i] += min(r[i-1], b[i-1]);
        b[i] += min(r[i-1], g[i-1]);
    }

    // 최소 비용 찾기
    int min = r[n-1];
    if(min > g[n-1]) {
        min = g[n-1];
    }
    if(min > b[n-1]) {
        min = b[n-1];
    }

    return min;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    r.assign(n, 0);
    g.assign(n, 0);
    b.assign(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> r[i] >> g[i] >> b[i];
    }

    int answer = findMinCost(n);

    cout << answer;

    return 0;
}