// 이진 검색 트리
#include <iostream>
#include <vector>
using namespace std;

int tree[10001];    // 주어진 전위 순회한 트리 저장
 
// end 는 (트리의 마지막 인덱스)+1
// tree[start] 를 루트 노드로 한다.
// tree에서 idx 를 기준으로, 
// 더 큰 인덱스를 가지는 쪽이 오른쪽 서브 트리이고,
// 더 작은 인덱스를 가지는 쪽이 왼쪽 서브 트리이다.
void postorder(int start, int end){
    if(start >= end){
        return;
    }

    int root = tree[start]; // 루트노드 tree[start]
    int idx = start+1;  // 왼쪽 서브 트리에서 오른쪽 서브 트리로 바뀌는 인덱스

    // idx를 찾는다
    while(idx<end){  
        // root 보다 큰 수부터 오른쪽 서브트리이다
        if(root < tree[idx])
            {break;}
        idx++;
    }

    postorder(start+1,idx); // 왼쪽 트리
    postorder(idx,end); // 오른쪽 트리
    cout << root << '\n';   // 후위 순회한 순서로 출력
}

int main(){
    ios_base:: sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    // 전위 순회(v-l-r)한 결과를 입력받아서 tree에 저장
    int input; 
    int idx = 0;

    while(cin >> input){
        tree[idx++] = input;
    }

    // 후위 순회(l-r-v)한 결과를 출력한다
    postorder(0,idx);

    return 0;
}