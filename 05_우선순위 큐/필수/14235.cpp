// 크리스마스 선물

#include <iostream>
#include <queue>
using namespace std;

int main()
{   
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x, k;
    priority_queue<int> gift;
    cin >> n;
    
    while (n--){
        cin >> x;
        if (x==0) // 아이들을 만난 경우
            if (gift.empty()) // 선물이 없음
                cout << -1 << '\n';
            else{
                cout << gift.top() << '\n';
                gift.pop();
            }
        else // 선물 충전
            while (x--){
                cin >> k;
                gift.push(k);
            }
    }
    return 0;
}