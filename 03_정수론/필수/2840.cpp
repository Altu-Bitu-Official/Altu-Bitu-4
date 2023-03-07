//
// Created by LG on 2023-03-07.
//
#include <iostream>
#include <queue>

using namespace std;

bool solve(queue<char> &roulette, int k){
    vector<bool> check(26, false);

    while(k--){
        int s;
        char c;
        cin >> s >> c;

        for(int i=0; i<s-1; i++){ //직전 칸은 queue뒤로 이미 이동 되었으므로 s-1번 칸 이동시킴
            char front = roulette.front();
            roulette.pop();
            roulette.push(front);
        }

        char stop = roulette.front(); //멈춘 칸에 적힌 문자
        roulette.pop();
        if(stop == '?'){ //빈 칸인 경우
            if(check[c-'A']) { //이미 등장했던 문자라면
                return false; //만들 수 없는 회전판
            }
            else { //등장하지 않았던 문자라면
                check[c-'A'] = true; //표시하고
                roulette.push(c); //해당 칸에 작성함
            }
        }
        else if(stop == c){ //멈춘 문자와 같은 문자인 경우
            roulette.push(stop); //queue 뒤로 넣어줌
        }
        else{ //멈춘 문자와 다른 문자인 경우
            return false; //만들 수 없는 회전판
        }
    }

    return true;
}

int main(){
    //입력
    int n, k;
    cin >> n >> k;

    queue<char> roulette;

    //칸이 n개인 회전판
    for(int i=0; i<n; i++){
        roulette.push('?');
    }

    if(solve(roulette, k)){ //만들 수 있는 회전판이면
        string ans = "";
        for(int i=0; i<n; i++){ //칸 개수만큼
            char front = roulette.front();
            roulette.pop();
            ans = front + ans; //정답 문자열 앞으로 붙임
        }
        cout << ans;
    }
    else{
        cout << '!';
    }

}
