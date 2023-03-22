#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    priority_queue<int, vector<int>> max_h;
    priority_queue<int, vector<int>, greater<int>> min_h;
    int input;
    while(n--){
        cin >> input;
        if(max_h.empty()==1){
            max_h.push(input);
        }
        
        else{
            
        if(max_h.size()-min_h.size()==0){
            max_h.push(input);
        }
        else {
            min_h.push(input);
        }
        if(max_h.top()>min_h.top()){
            int maxTop=max_h.top();
            int minTop=min_h.top();

            max_h.pop();
            min_h.pop();
            max_h.push(minTop);
            min_h.push(maxTop);
        }
        }
        

        
         cout <<max_h.top() << '\n';
    }
   
    
}