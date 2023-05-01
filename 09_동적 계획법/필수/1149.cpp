#include <iostream>
#include <vector>

using namespace std;

int calcCost(int n,int v [][3]){

    vector<vector<int>> dp(n+1,vector<int>(3,0)); //(n,0) - n번째 집을 빨간색으로 칠함
    //0번째 집은 없으므로 0으로 초기화
    dp[0][0] = 0;
    dp[0][1]=0;
    dp[0][2]=0;
    for(int i=1;i<=n;i++){
        dp[i][0] =min(dp[i-1][1],dp[i-1][2])+v[i-1][0]; //i번째집을 칠할 때 i-1번째 집은 i번째 집이 칠하지 않은 색으로 칠해야함. 그 중 최솟값+i번째집 칠할 때 드는 비용
        dp[i][1] =min(dp[i-1][0],dp[i-1][2])+v[i-1][1];
        dp[i][2] =min(dp[i-1][0],dp[i-1][1])+v[i-1][2];
    }

    //n번째 집 0,1,2 중 최소 비용 구한 후 return

    int result = min(dp[n][0],dp[n][1]);
    result = min(result,dp[n][2]);

    return result;
}

int main(){
    int n;
    cin >>n;
    int v[n][3];
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >>v[i][j];
        }
    }

    int ans = calcCost(n,v);


    cout <<ans;

    return 0;
}

