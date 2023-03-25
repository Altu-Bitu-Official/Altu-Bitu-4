#include "iostream"
#include "vector"
#include "stack"

using namespace std;

long long getStartV(stack<int>&velocity){
    long long start_v = velocity.top();   // start_v 초기화
    velocity.pop();

    while(!velocity.empty()){
        if(velocity.top() >= start_v){
            start_v = velocity.top();
        }
        else{
            if (start_v % velocity.top()){
                start_v = ((start_v / velocity.top()) +1) * velocity.top();
            }
        }
        velocity.pop();
    }
    return start_v;
}

int main(){
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    stack<int> velocity;

    // 입력
    cin >> n;

    while(n--){
        cin >> tmp;
        velocity.push(tmp);
    }

    cout << getStartV(velocity);
}