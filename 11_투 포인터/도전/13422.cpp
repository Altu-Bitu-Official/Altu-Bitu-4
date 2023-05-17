// 도둑

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

void chooseHouse(int n, int m, int k, int tot_cost, vector<int> &house){
    int num = 0, cost = 0;
    if (n == m){ // 모든 집을 지나가면
        if (tot_cost < k){
            num++;
        }
        cout << num << '\n';
        return;
    }
    // 0~(m-1) 집 탐색
    for (int i = 0; i < m; i++){
        cost += house[i];
    }
    if (cost < k){
        num++;
    }
    // 슬라이딩 윈도우
    for (int i = m; i < n + m -1; i++){
        cost = cost + house[i] - house[i-m];
        if (cost < k){
            num++;
        }
    }
    cout << num << '\n';
    return;
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
    int t, n, m, k;
    cin >> t;
    while (t--){
        cin >> n >> m >> k;
        vector<int> house(n+m-1,0);
        int cost = 0; // cost 초기화
        for (int i = 0; i < n; i++){
            cin >> house[i];
            cost += house[i];
        }
        for (int i = n; i < n + m -1; i++){ // 원형으로 만들기
            house[i] = house[i-n];
        }
        chooseHouse(n, m, k, cost, house);
    }
    return 0;
}