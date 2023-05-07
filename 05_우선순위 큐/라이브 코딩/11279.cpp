// 최대 힙

#include <iostream>
#include <queue>

using namespace std;


int main()
{   
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, x;
    priority_queue<int> max_heap;
    
    cin >> n;
    while (n--){
        cin >> x;
        if (x==0){ 
            if (max_heap.empty()) // 비어있다면 0출력
                cout << "0\n";
            else{ // 가장 큰 값 출력하고 제거
                cout << max_heap.top() << '\n';
                max_heap.pop();
            }
        }
        else{ // x 삽입
            max_heap.push(x);
        }
    }
    return 0;
}