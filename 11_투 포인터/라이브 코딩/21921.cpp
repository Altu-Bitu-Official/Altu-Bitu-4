// 블로그

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int x, n, cur_visitor;
    
    cin >> n >> x;
    vector<int> visitor(n, 0); // 일별 방문자수
    vector<int> x_visitor(n-x+2,0); // x일 동안 방문자 수
    
    for (int i = 0; i<n; i++){
        cin >> visitor[i];
    }
    // 첫째항 계산
    for (int i = 0; i<x; i++){
        x_visitor[0] += visitor[i]; // 0번째 : 0~(x-1) 기간동안 방문자 수
    }
    int max_val = x_visitor[0], cnt = 1;
    // 이후 항 계산
    for (int i = 1; i < (n-x+1); i++){ // i번째 : i~(x-1+i) (기간동안 방문자 수
        x_visitor[i] = x_visitor[i-1] - visitor[i-1] + visitor[x-1+i];
        
        if (x_visitor[i] > max_val){ // 최댓값 초기화
            max_val = x_visitor[i];
            cnt = 1;
        }
        else if (x_visitor[i] == max_val){
            cnt++;
        }
    }
    if (max_val == 0){
        cout << "SAD";
    }
    else{
        cout << max_val << '\n' << cnt;
    }
    return 0;
}