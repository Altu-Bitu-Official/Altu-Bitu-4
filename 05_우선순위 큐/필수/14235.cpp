#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    priority_queue<int, vector<int> > q;

    while(n--){
        int num;
        cin >> num;
        if(num == 0){
            //pop
            if(q.empty()){
                cout << "-1\n";
            }
            else{
                cout << q.top() << "\n";
                q.pop();
            }
        }
        else {
            while(num--){
                int present;
                cin >> present;
                q.push(present);
            }
        }
    }
}