#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    int cost[n][3]; 
    int color[n][3];// color[i][j] : i번째 집을 j색으로 칠하는 비용

    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> cost[i][j];
        }
    }

    color[0][0] = cost[0][0];
    color[0][1] = cost[0][1];
    color[0][2] = cost[0][2];

    for(int i=1; i<n; i++){
        color[i][0] = min(color[i-1][1], color[i-1][2]) + cost[i][0]; 
        //i-1번째 집을 다른색으로 칠한 경우 중 더 비용이 적은 수 + 현재 집의 비용
        color[i][1] = min(color[i-1][0], color[i-1][2]) + cost[i][1];
        color[i][2] = min(color[i-1][0], color[i-1][1]) + cost[i][2];
    }

    int Min = min({color[n-1][0],color[n-1][1],color[n-1][2]});

    cout<<Min;

    return 0;
}