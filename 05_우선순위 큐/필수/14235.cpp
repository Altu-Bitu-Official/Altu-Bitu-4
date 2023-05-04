#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, present, get_new;
    cin >> n;
    priority_queue<int> santa_sleigh;
    for(int i=0; i<n; i++){
        cin >> present;

        if(present == 0){
            if (santa_sleigh.empty()) { // 비어있다면 -1출력
				cout << "-1\n";
			}
            else{
                cout << santa_sleigh.top() << '\n';
                santa_sleigh.pop();
            }
        }
        else{
            for(int j=0; j<present; j++){
                cin >> get_new;
                santa_sleigh.push(get_new); //선물 충전
            }
        }
    }

    
    return 0;
}