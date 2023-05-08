// 테트로미노

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool visited[500][500]; // 방문여부 저장
vector<int> result;
int sum = 0;
int cursum = 0;

// 특정 위치에서 시작할 때 최댓값 탐색
int findMax(int idx_1, int idx_2, int m, int n, int cnt, int cursum, int sum, vector<vector<int>> &terr){
    if (cnt == 4){ // 종료 조건
        cout << cursum << " ";
        if (cursum > sum){
            sum = cursum; // sum 갱신
            return sum;
        }
    }
    int dr[3] = {0, 1, 0}; // 탐색 방향
    int dc[3] = {-1, 0, 1};
    cursum += terr[idx_1][idx_2];
    for (int i=0; i<3; i++){
        if ((0<= idx_1 + dr[i] < m) & (0 <= idx_2 + dc[i] < n)  & (!visited[idx_1 + dr[i]][idx_2 + dc[i]])){
            visited[idx_1 + dr[i]][idx_2 + dc[i]] = true;
            findMax(idx_1 + dr[i], idx_2 + dc[i], m, n, cnt+1, cursum, sum, terr);
            visited[idx_1 + dr[i]][idx_2 + dc[i]] = false;
        }
    }
    return sum;
}

int solution(int m, int n, vector<vector<int>> &terr){
    int sum = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j<n; j++){
            visited[i][j] = true;
            int x = findMax(i, j, m, n, 1, 0, sum, terr);
            if (sum < x){ // sum 갱신
                sum = x;
            }
            visited[i][j] = false;
        }
    }
    return sum;
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> terr(m, vector<int> (n, 0));
    
    for (int i=0; i<m; i++){
        for (int j = 0; j<n; j++){
            cin >> terr[i][j];
        }
    }
    cout << solution(m, n, terr);
    return 0;
}