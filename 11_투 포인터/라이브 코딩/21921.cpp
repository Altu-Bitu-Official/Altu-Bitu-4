#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> ci;

ci slidingWindow(vector<int> &count, int n, int x){
    int left = 1, right = x;
    int visitor = 0;
    int cnt = 1;

    for(int i = left; i<=right; i++){
        visitor += count[i];
    }
    int max_visitor = visitor;

    while(right < n){
        //윈도우 한 칸씩 오른쪽으로 이동
        visitor -= count[left++];
        visitor += count[++right];

        if(visitor > max_visitor){
            max_visitor = visitor;
            cnt = 1;
        }
        else if (visitor == max_visitor){
            cnt++;
        }
    }
    return {max_visitor, cnt};
}

int main(){
    int x, n;
    vector<int> count;

    //입력
    cin >> n >> x;
    count.assign(n+1, 0);
    for(int i=1; i<=n; i++){
        cin >> count[i];
    }
    //연산
    ci ans = slidingWindow(count, n, x);

    if(ans.first == 0){
        cout << "SAD";
    }
    else{
        cout << ans.first << "\n" << ans.second;
    }
}