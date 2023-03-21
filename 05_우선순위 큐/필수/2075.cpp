#include <iostream>
#include <vector>

using namespace std;

void push(vector<int> &heap, int x){
    int index = heap.size();
    heap.push_back(x);

    while(index >1 && heap[index] > heap[index/2]){
        swap(heap[index], heap[index/2]);
        index/=2;
    }
    return;
}

int pop(vector<int> &heap){
    int root = heap[1];
    heap[1] = heap[heap.size()-1];
    heap.pop_back();

    int size = heap.size();
    int parent = 1, child = 2;

    while(child<size){
        if(child+1<size && heap[child+1]> heap[child]){
            child+=1;
        }
        if(heap[parent] < heap[child]){
            swap(heap[parent], heap[child]);
            parent = child;
            child = parent*2;
        }
        else{
            break;
        }
    }
    return root;
}

int main(){
    int N, x;
    cin >> N;

    vector<int> heap_vec;
    heap_vec.push_back(0);

    for( int i=1; i<=N*N; i++){
        cin >> x;
        push(heap_vec, x);
    }

    for( int i =0; i<N; i++){
        if(i == N-1){
            cout << pop(heap_vec) << endl;
        }
        else{
            pop(heap_vec);
        }
    }
    return 0;
}