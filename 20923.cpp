// 20923 숫자 할리갈리 게임
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

void play_game(deque<int> card[], deque<int> ground[], int &M){
    int cur_idx= 0;
    while(M--){
        int t = card[cur_idx].front();
        ground[cur_idx].push_front(t);
        card[cur_idx].pop_front();
        if(card[cur_idx].empty()){
            if(cur_idx == 0) {
                cout << "do";
            }
            else {
                cout << "su";
            }
        }
        int chk = 0; //누가 이겼는지 체크해주는 변수 (0, 1)이면 각각 do, su가 이긴 것
        // -1이면 x
        if(ground[0].size() && ground[0].front() == 5){
            chk = 0;
        }
        else if(ground[1].size() && ground[1].front() == 5){
            chk = 0;
        }
        else if(ground[0].front() + ground[1].front() == 5){
            if(ground[0].size() && ground[1].size()){
            chk = 1;
            }   
        }
        else {
            chk = -1;
        }
    if(chk != - 1){
            int tmp = 1- chk;
            while(ground[tmp].size()) {
            int t = ground[tmp].back();
            card[chk].push_back(t);
            ground[tmp].pop_back();
            }
            while(ground[chk].size()) {
            int t = ground[chk].back();
            card[chk].push_back(t);
            ground[chk].pop_back();
            }
        }
        cur_idx = 1- cur_idx;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int N, M;
    deque<int> card[2];
    deque<int> ground[2];
    cin >> N >> M;
    while(N--){
        int x, y;
        cin >> x >> y;
        card[0].push_back(x);
        card[1].push_back(y);
    }
    play_game(card, ground, M);
    if(card[0].size() > card[1].size()){
        cout << "do";
    }
    else if(card[0].size() < card[1].size()){
        cout << "su";
    }
    else {
        cout << "dosu";
    }
}