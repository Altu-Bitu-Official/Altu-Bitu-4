/*
----------- 틀린 코드 -----------
--- 주어진 테스트 케이스들은 다 통과하는데, 원인을 찾지 못하여 튜터님께서 올려주신 풀이 코드에 주석을 달아 제출합니다. ---
// 20923 숫자 할리갈리 게임
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
const int DO_WIN = 0; //도도가 이겼을 때
const int SU_WIN = 1; //수연이가 이겼을 때
const int ERR = -1; //예외 케이스
int ringingBell(deque<int> ground[]){
    // -1이면 x
    if(ground[0].size() && ground[0].front() == 5){
            return DO_WIN;
    }
    else if(ground[1].size() && ground[1].front() == 5){
            return DO_WIN;
    }
    else if(ground[0].front() + ground[1].front() == 5){
        if(ground[0].size() && ground[1].size()){
            return SU_WIN;
            }   
        }
    else {
         return ERR;
    }
}

void playGame(deque<int> card[], deque<int> ground[], int &M){
    int cur_idx= 0;
    while(M--){
        int t = card[cur_idx].front(); // 이번 턴에서 카드를
        ground[cur_idx].push_front(t); // 땅에 내려놓고
        card[cur_idx].pop_front(); //카드 덱에서 내려놓은 카드를 빼어준다.
        if(card[cur_idx].empty()){ // 카드 덱이 비었다면
            if(cur_idx == 1) {
                cout << "do"; 
            }
            else {
                cout << "su";
            }
          return;
        }
    int chk = 0;
    chk = ringingBell(ground);
    if(chk != ERR){
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
      if(card[0].size() < card[1].size()){
        cout << "do";
    }
    else if(card[0].size() > card[1].size()){
        cout << "su";
    }
    else if(card[0].size() == card[1].size()){
        cout << "dosu";
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
    playGame(card, ground, M);
}
*/

//20923 숫자 할리갈리 게임
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

typedef vector<deque<int>> cards;
const int DO = 0, SU = 1;
const int NO_RANG = -1;
//누가 이겼는지 판단하기
string whoseWin(cards &deck){
    int do_deck = deck[DO].size(), su_deck = deck[SU].size();
    if(do_deck > su_deck) { // 현재 남아있는 카드 덱의 사이즈가 도도가 더 크면
        return "do"; // 도도의 승리
    }
    else if(do_deck < su_deck){ // 현재 남아있는 카드 덱의 사이즈가 수연이가 더 크면
        return "su"; // 수연이의 승리
    }
    else {
        return "dosu"; // 둘이 비김.
    }
}

// 그라운드에서 덱으로 카드 옮기기(종을 칠 때, 종을 먼저 친 사람이 카드를 다 가져가는 식)
void groundToDeck(deque<int> &deck, deque<int> &ground){
    while(!ground.empty()){ // 그라운드에 있는 카드가 빌 때까지
        int card = ground.back(); // 그라운드 뒤에 있는(like 스택) 카드들을 꺼내어(순서 보장)
        deck.push_back(card); // 본인 카드 덱에 넣고
        ground.pop_back(); // 그라운드에서 빼준다.
    }
}

// 종을 치고 난 후, 카드를 가져간다.
void ringingBell(int player, cards &deck, cards &ground){
    groundToDeck(deck[player], ground[!player]); // 카드 가져가기 (상대 그라운드에 있는 카드->본인 카드 덱)
    groundToDeck(deck[player], ground[player]); // (본인 그라운드에 있는 카드->본인 카드 덱)
}

// 누가 해당 턴에서 벨을 울렸는가?
int whoRangBell(cards &deck, cards &ground){
    // 둘의 카드 덱이 비지 않은 상태에서, 어느 누군가 5개가 있는 카드를 꺼냈다면 도도의 승리
    if(!ground[DO].empty() && ground[DO].front() == 5) {
        return DO;
    }
    else if(!ground[SU].empty() && ground[SU].front() == 5){
        return DO;
    }
    // 둘의 카드 덱이 비지 않은 상태에서, 둘이 지금 꺼낸 카드 상태의 합이 5이면 수연이의 승리
    else if(!ground[DO].empty() && !ground[SU].empty()){
        if(ground[DO].front() + ground[SU].front() == 5){
            return SU;
        }
    }
    return NO_RANG; // 이번 턴에서는 종을 울릴 수 없다.
}

// 게임 구현 
string playGame(int m, cards &deck, cards &ground){
    bool turn = DO; // 도도가 맨 처음 먼저 시작합니다.
    while(m--){
        int tmp = deck[turn].front(); // 덱에서 그라운드로 카드를 내려놓으며 게임을 진행합니다.
        ground[turn].push_front(tmp); // 그라운드에 카드를 놓기
        if (deck[turn].empty()){
            break;
        }
        int bell = whoRangBell(deck, ground); // 종을 울렸는가?(-1이 아니면 종을 울렸다는 의미)
        if(bell != NO_RANG){ //종을 울렸더라면
            ringingBell(bell, deck, ground); // 종을 울린 사람이 본인의 그라운드+상대방 그라운드 카드를 전부 가져간다.
        }
        turn = !turn; // 차례를 바꾼다. (도도->수연), (수연->도도)
    }
    return whoseWin(deck);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, card1, card2;
    cards deck(2), ground(2); //2차원 덱 배열 생성
    // 입력
    while(n--){
        cin >> card1 >> card2;
        deck[DO].push_front(card1);
        deck[SU].push_front(card2);
    }
    cout << playGame(m, deck, ground) << "\n";
    return 0;
}
