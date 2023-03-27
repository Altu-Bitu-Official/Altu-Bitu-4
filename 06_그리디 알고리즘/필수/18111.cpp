// 마인크래프트

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1e9;

using namespace std;

int minecraft(vector<int> ground, int h, int b){
    int t = 0; // 시간
    for (int i=0; i<ground.size(); i++){
        if (ground[i] > h){ // 높이보다 높으면
            t+= 2*(ground[i]-h);
            b+= (ground[i]-h);
        }
        else if (ground[i] < h){ // 높이보다 낮으면
            t += (h-ground[i]);
            b -= (h-ground[i]);
        }
    }
    if (b>=0)
        return t;
    else
        return MAX;
}

int main()
{
    int n, m, b, t, ans1, ans2;
    cin >> n >> m >> b;
    
    vector<int> ground(n*m);
    for (int i=0; i<n*m; i++){
        cin >> ground[i];
    }
    // 땅 최소/최대 높이
    int min = *min_element(ground.begin(), ground.end());
    int max = *max_element(ground.begin(), ground.end());
    
    ans1 = MAX; // 초기화
    for (int h = min; h <= max; h++){ // 가능한 높이에 대해 시간 측정
        t = minecraft(ground, h, b);
        if (t <= ans1){
            ans1 = t; ans2 = h;
        }
    }
    cout << ans1 << " " << ans2;
    
    return 0;
}