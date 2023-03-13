// 꽃길

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// 다른 꽃과 겹치지 않는지 판단
int planting(int x1, int y1, int x2, int y2){
    if ((abs(x2-x1) + abs(y2-y1))>2) // L1거리가 2보다 크면 꽃을 심을 수 있음.
        return 1; 
    return 0;
}

int main()
{   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n, v, cost = 3000;
    cin >> n;
    int s[n][n] = {0,};
    int price[n-2][n-2] = {0,};
    
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++){
            cin >> v;
            s[i][j] = v;
    }
    // 비용 계산
    for (int i=1; i<n-1; i++)
        for (int j=1; j<n-1; j++)
            price[i-1][j-1] = s[i][j-1] + s[i][j] + s[i][j+1] + s[i-1][j] + s[i+1][j];
    
    // 최적 비용 찾기
    for (int x1=0; x1<n-4; x1++){
        for (int y1=0; y1<n-4; y1++)
            for (int x2=0; x2<n-3; x2++)
                for (int y2=0; y2<n-3; y2++)
                    if (planting(x1, y1, x2, y2)) // 꽃을 심을 수 있으면
                        for (int x3=0; x3<n-2; x3++)
                            for (int y3=0; y3<n-2; y3++)
                                if (planting(x1, y1, x3, y3) & planting(x2, y2, x3, y3))
                                    cost = min(cost, (price[x1][y1] + price[x2][y2] + price[x3][y3]));
    }
    cout << cost;
}