#include "iostream"
#include "vector"
#include "stack"

using namespace std;

long long getStartV(stack<int>&velocity){
    long long start_v = velocity.top();   // start_v를 Vn으로 초기화
    velocity.pop(); // Vn을 pop

    // velocity가 빌 때까지
    // velocity.top()이 현재 start_v보다 크거나 같다면 top을 start_v에 저장. => 큰 속도에서 작은 속도로 갈때는 배수 고려없이 그냥 낮추면 됨.
    // velocity.top()이 현재 start_v보다 작다면 start_v는 현재 start_v보다 큰 top의 배수 중 가장 작은 값이다.
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
    // 연산과 출력
    cout << getStartV(velocity);
}