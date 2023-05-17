// 숫자 할리갈리 게임

#include <iostream>
#include <deque>

using namespace std;

void Bell(deque<int> &dodo, deque<int> &sue, int n1, int n2, int win){
    
    if (win == 1){ // 도도가 이기면
        for (int k = 0; k < n2; k++){ // 도도가 수연이 카드를 가져옴
            dodo.push_back(sue[0]);
            sue.pop_front();
        }
        for (int k = 0; k< n1; k++){ // 도도 자신의 카드를 가져옴.
            dodo.push_back(dodo[0]);
            dodo.pop_front();
        }
    }
    else{ // 수연이가 이기면
        for (int k=0; k<n1; k++){ // 수연이가 도도의 카드를 가져옴
            sue.push_back(dodo[0]);
            dodo.pop_front();
        }
        for (int k=0; k<n2; k++){ // 수연이가 자신의 카드를 가져옴.
            sue.push_back(sue[0]);
            sue.pop_front();
        }
    }
}

int playGame(deque<int> &dodo, deque<int> &sue, int m){
    
    int n1 = 0, n2 = 0; // 종을 친 이후 도도, 수연이가 낸 카드 수

    for (int turn = 0; turn < m; turn ++){ // m번 반복
    
        if (turn % 2 == 0){ // 도도가 카드를 낼 차례이면
            if (dodo.size() <= n1 + 1){ // 도도가 더이상 카드가 없으면 수연 승
                return 2;
            }
            n1++; // 도도가 카드를 냄
            if (dodo[n1-1] == 5){ // 도도가 5를 냄
                Bell(dodo, sue, n1, n2, 1);
                n1 = 0; n2 = 0; // 벨을 치면 카드 수 초기화
            }
            else if (n2 >= 1 and (dodo[n1-1] + sue[n2-1]) == 5){ // 두 카드의 합이 5이면 
                Bell(dodo, sue, n1, n2, 2);
                n1 = 0; n2 = 0;
            }
        }
        else { // 수연이가 카드를 낼 차례이면
            if (sue.size() <= n2 + 1){ // 수연이가 더이상 카드가 없으면 도도 승
                return 1;
            }
            n2++;
            if (sue[n2-1] == 5){ // 수연이가 5를 냄
                Bell(dodo, sue, n1, n2, 1); // 도도가 종을 침
                n1 = 0; n2 = 0;
            }
            else if (n1 >= 1 and (dodo[n1-1] + sue[n2-1]) == 5){ // 두 카드의 합이 5이면 
                Bell(dodo, sue, n1, n2, 2); // 수연이가 종을 침
                n1 = 0; n2 = 0;
            }
        }
    }
    if (dodo.size()-n1 > sue.size()-n2){
        return 1;
    }
    else if (dodo.size()-n1 < sue.size()-n2){
        return 2;
    }
    else{
        return 3;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n, m, a, b;
    cin >> n >> m;
    
    deque<int> dodo;
    deque<int> sue;
    
    while (n--){ // 입력
        cin >> a >> b;
        dodo.push_front(a);
        sue.push_front(b);
    }
    
    int ans = playGame(dodo, sue, m);
    
    if (ans == 1){
        cout << "do";
    }
    else if (ans == 2){
        cout << "su";
    }
    else{
        cout << "dosu";
    }
    return 0;
}