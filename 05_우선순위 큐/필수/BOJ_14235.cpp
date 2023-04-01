#include <iostream>
#include <queue>

using namespace std;


//선물과 입력을 받고 선물을 나눠주거나, 선물을 저장하는 함수
void givePresent(priority_queue<int>& present, int input) {
    if(!input) {    //선물을 줄 때
        if(present.empty()) {
            cout << -1 << '\n';
            return;
        }
        cout << present.top() << '\n';
        present.pop();
        return;
    }
    //선물을 저장할 때
    while(input--) {
        int n;
        cin >> n;
        present.push(n);
    }
    return;
}

int main() {
    int n;
    priority_queue<int> present;
    //입력
    cin >> n;

    while(n--) {
        int input;
        cin >> input;
        givePresent(present, input);
    }
    
}