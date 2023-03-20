#include <iostream>
#include <queue>

using namespace std;

int checkGift(priority_queue<int> &h){
    //줄 선물이 없으면 -1 출력
    if(h.empty()){
        return -1;
    }
    //줄 선물이 있으면 
    int tmp = h.top();
    h.pop();
    return tmp;
}

int main()
{
    int n, a, value;
    priority_queue<int> h;

    //입력
    cin >> n;
    //n번 반복
    while(n--) {
        cin >> a;
        //아이 만남
        if(a == 0){
            //선물 출력
            cout << checkGift(h) << '\n';
            continue;
        }
        //선물 충전
        while(a--){
            //선물 가치 입력 & 추가
            cin >> value;
            h.push(value);
        }
    }
}