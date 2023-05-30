// 키 순서 
#include <iostream>
#include <vector>
using namespace std;

void floydWarshall(int n, vector<vector<bool>> &height){
    for (int k = 1; k<=n; k++){ // 중간 정점
        for (int i = 1; i<=n; i++){ // 시작 정점
            for (int j = 1; j<=n; j++){ // 도착 정점
                if (height[i][k] and height[k][j]){ // i -> j -> k로 연결되면
                    height[i][j] = true;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <=n; i++){ // i번 정점 탐색
        int cnt = 1;
        for (int j = 1; j<=n; j++){
            cnt += (height[i][j] or height[j][i]); // i와 j가 연결되면
        }
        if (cnt == n){
            ans++;   
        }
    }
    
    cout << ans;
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    vector<vector<bool>> height(n+1, vector<bool>(n+1, false));
    
    while (m--){
       cin >> a >> b;
       height[a][b] = true; // a->b 연결
    }
    floydWarshall(n, height);
    return 0;
}