// 테트로미노

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

bool visited[500][500]; // 방문여부 저장
int sum = 0;

// 특정 위치에서 시작할 때 최댓값 탐색
void findMax(int idx_1, int idx_2, int m, int n, int cnt, int cursum, vector<vector<int>> &terr){
    if (cnt == 4){ // 종료 조건
        sum = max(cursum, sum); // sum 갱신
        return;
    }
    int dr[] = {0, 1, 0, -1}; // 탐색 방향
    int dc[] = {-1, 0, 1, 0};
    cursum += terr[idx_1][idx_2]; 
    for (int i = 0; i < 4; i++){ //  4개가 모두 한 선으로 이어지는 도형 탐색
        if ((0<= idx_1 + dr[i]) && (idx_1 + dr[i] < m) && (0 <= idx_2 + dc[i]) && (idx_2 + dc[i] < n)  && (!visited[idx_1 + dr[i]][idx_2 + dc[i]])){
            visited[idx_1 + dr[i]][idx_2 + dc[i]] = true;
            findMax(idx_1 + dr[i], idx_2 + dc[i], m, n, cnt+1, cursum, terr);
            visited[idx_1 + dr[i]][idx_2 + dc[i]] = false;
        }
        else{ // 더이상 갈곳이 없으면 pass
            continue;
        }
    }
}
// ㅜ모양 탐색
void findO(int idx_1, int idx_2, int m, int n, vector<vector<int>> &terr){
   int cnt = 0; // 탐색 가능 방향 개수 세기
   int dr[] = {0, 1, 0, -1}; // 탐색 방향
   int dc[] = {-1, 0, 1, 0};
   int sumO = terr[idx_1][idx_2];
   for (int i=0; i<4; i++){
       if ((0<= idx_1 + dr[i]) && (idx_1 + dr[i] < m) && (0 <= idx_2 + dc[i]) && (idx_2 + dc[i] < n)  && (!visited[idx_1 + dr[i]][idx_2 + dc[i]])){
            cnt++;
            sumO += terr[idx_1 + dr[i]][idx_2 + dc[i]];
        }
   }
   if (cnt < 3){ // 탐색 가능 방향이 2개 이하이면 pass
       return;
   }
   else if (cnt == 3){
       sum = max(sum, sumO);
   }
   else{ // 모든 방향이 탐색 가능하면
       int minO = min({terr[idx_1 + dr[0]][idx_2 + dc[0]], terr[idx_1 + dr[1]][idx_2 + dc[1]], terr[idx_1 + dr[2]][idx_2 + dc[2]], terr[idx_1 + dr[3]][idx_2 + dc[3]]});
       sum = max(sum, sumO - minO);
   }
}

int solution(int m, int n, vector<vector<int>> &terr){
    for (int i = 0; i < m; i++){
        for (int j = 0; j<n; j++){
            int cursum = 0; // cursum 초기화
            visited[i][j] = true;
            findMax(i, j, m, n, 0, 0, terr);
            visited[i][j] = false;
            findO(i, j, m, n, terr);
        }
    }
    return sum;
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<vector<int>> terr(m, vector<int> (n, 0));
    
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            cin >> terr[i][j];
        }
    }
    cout << solution(m, n, terr);
    return 0;
}