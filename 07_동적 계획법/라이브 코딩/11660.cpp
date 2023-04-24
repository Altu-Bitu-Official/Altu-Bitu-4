// 구간 합 구하기 5

#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void calcPsum(int n, vector<vector<int>> &A, vector<vector<int>> &psum){
    // psum[i][j]: (1,1)부터 (i,j)까지의 합
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            psum[i][j] = psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1] + A[i][j];
        }
    }
}

int calcSum(int x1, int y1, int x2, int y2, vector<vector<int>> &psum){
    return psum[x2][y2] - psum[x2][y1-1] - psum[x1-1][y2] + psum[x1-1][y1-1];
}

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> A(n+1, vector<int>(n+1, 0));
    vector<vector<int>> psum(n+1, vector<int>(n+1, 0));
    
    for (int i=1; i<=n; i++)
        for (int j = 1; j<=n; j++)
            cin >> A[i][j];
        
    // 연산: 누적합 테이블 구해두기
    calcPsum(n, A, psum);
   
    for (int i=0; i<m; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int answer = calcSum(x1, y1, x2, y2, psum);
        cout << answer << '\n';
    }

    return 0;
}