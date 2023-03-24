#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n,a,gift;
    cin >> n;
    priority_queue<int> que;

    for(int i =0 ; i < n; i++){
        cin >> a;
        if (a == 0){
            if(que.empty()){
                cout<< "-1"<<endl;
            }
            else{
                cout<< que.top()<<endl;
                que.pop();
            }
        }
        else{
            while(a--){
                cin>>gift;
                que.push(gift);
            }
        }
    }
    return 0;
}