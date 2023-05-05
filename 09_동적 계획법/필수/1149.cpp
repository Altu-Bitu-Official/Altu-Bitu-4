#include <vector>
#include "algorithm"
#include "iostream"

using namespace std;

int dp(vector<vector<int>> rgb, int n){
    vector<vector<int>> cost (n, vector<int>(3));
    cost[0] = {rgb[0][0], rgb[0][1], rgb[0][2]};

    for(int i=1; i<n; i++){
        for(int j=0; j<3; j++){
            cost[i][j] = min(cost[i-1][(j+1)%3], cost[i-1][(j+2)%3]) + rgb[i][j];
        }
    }
    return min({cost[n-1][0], cost[n-1][1], cost[n-1][2]});
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> rgb(n, vector<int>(3));
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> rgb[i][j];
        }
    }
    cout << dp(rgb, n);
}