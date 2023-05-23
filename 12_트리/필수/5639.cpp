// 트리와 쿼리 - OutofBounds 오류 
#include <iostream>
#include <vector>
using namespace std;
// 후위순회
void postorder(int parent, vector<int> &node){
    if (node[parent] == 0){ // 종료조건 - 노드가 없으면
        return;
    }
    postorder(parent*2, node);
    postorder(parent*2+1, node);
    if (node[parent] != 0){
        cout << node[parent] << '\n';
    }
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    vector<int> node(Inf,0); // node수가 무한 -> 구현 불가
    node[0] = 1e6;
    cin >> node[1]; // 루트노드
    int x, parent = 1;
    while (cin >> x){
        if (x < node[parent]){ // 부모 노드보다 작으면 왼쪽 노드
            parent = 2*parent;
            node[parent] = x;
        }
        else{ // 부모 노드보다 크면
            while (true){
                if (x > node[parent] and x < node[parent/2]){ // 왼쪽 노드는 있고, 오른쪽 노드는 비어있으면
                    parent = 2*parent + 1;
                    node[parent] = x;
                    break;
                }
                else{ // 둘다 차있으면
                    parent /= 2;
                }
            }
        }
    }
    postorder(1, node);
    return 0;
}