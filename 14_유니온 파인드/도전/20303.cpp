#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> ci;

vector<ci> parent;

int knapsack(int n, int k) {
    vector<ci> collected; //first: 아이들의 수, second: 총 사탕 개수
    for (int i = 1; i <= n; i++) {
        if (parent[i].first < 0) { // 루트 정점인 경우 (각 친구 집합에 대하여)
            collected.push_back({ -parent[i].first, parent[i].second });
        }
    }
    vector<int> dp(k, 0); // 1부터 k-1까지
    for (int i = 0; i < collected.size(); i++) {
        for (int j = k - 1; j >= collected[i].first; j--) {
            dp[j] = max(dp[j], dp[j - collected[i].first] + collected[i].second);
        }
    }
    return dp[k - 1];
}

//Find 연산
int findParent(int node) {
    if (parent[node].first < 0) { 
        return node;
    }
    return parent[node].first = findParent(parent[node].first);
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) { 
        return;
    }
    if (parent[xp].first < parent[yp].first) { 
        parent[xp].first += parent[yp].first;   // 아이의 수 더하기
        parent[xp].second += parent[yp].second; // 사탕 더하기
        parent[yp].first = xp;
    }
    else {
        parent[yp].first += parent[xp].first;
        parent[yp].second += parent[xp].second;
        parent[xp].first = yp;
    }
}

/*
* weighted union find -> 루트 정점에 친구인 아이들의 수(집합 원소 수)와 그들이 가진 총 사탕 개수를 pair로 저장
* 냅색(dp)으로 K명 미만의 아이들에게서 빼앗을 수 있는 최대 사탕 수 계산
*/

int main() 
{
    int n, m, k, a, b;
    // 입력
    cin >> n >> m >> k;
    parent.assign(n + 1, { -1, 0 }); //first: 아이들의 수, second: 총 사탕 개수
    for (int i = 1; i <= n; i++) {
        cin >> parent[i].second;
    }
    while (m--) {
        cin >> a >> b;
        unionInput(a, b);
    }
    // 연산 & 출력
    cout << knapsack(n, k) << '\n';
    return 0;
}