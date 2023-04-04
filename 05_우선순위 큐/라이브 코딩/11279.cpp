#include <iostream>
#include <vector>
#include <queue>
/*
필기))
heap에서 데이터 삭제 시. 루트 노드부터 나가는데.
루트노드를 비워둘 수 없으므로
하나를 루트 자리에 앉혀두고 걔를 밑으로 내리면서 자리를
찾아준다.
자식노드를 찾아주기 위해서 배열의 인덱스 1부터 노드를
배정하는 것이다...


*/
using namespace std;

bool isEmpty(vector<int> &heap){
    return heap.size()==1;//사이즈가 1이면 empty
}

int pop(vector<int> &heap){
    int top=heap[1];//루트노드에 있는 값 따로 저장
    heap[1]=heap[heap.size()-1];//루트노드를 없애고 마지막 노드를 루트에 데려다놓음.  
    heap.pop_back();//마지막 노드 요소 삭제

    int parent=1, child=2;//검사할 부모와 자식 노드 위치의 초기값.
    
    while(child < heap.size()){
        if(child+1<heap.size() && heap[child+1]<heap[child]){
            child+=1;
        }

        if(heap[parent]<heap[child]){
            swap(heap[parent],heap[child]);
            parent=child;
            child=parent*2;
        }
        else{
            break;
        }
    }
    return top;
}

void push(vector<int> &heap, int x){
    int idx=heap.size();
    heap.push_back(x);
    while(idx > 1 && heap[idx/2] < heap[idx]){
        swap(heap[idx/2],heap[idx]);
        idx/=2;
        }
}

int main(){
    int n,x;
    priority_queue<int> pq;

   
    cin >> n;

    while(n--){
        cin >> x;
        if(x==0){
            //힙이 비었다면 0을 출력하고
            if(pq.empty()){
                cout << "0\n";
            }
            //아니라면 배열에서 가장 큰값을 pop한다.
            else{
                cout<<pq.top() << '\n';
                pq.pop();
            }
        }
        else{
            //해당 자연수를 삽입.
            pq.push(x);
        }
    }
    return 0;
}