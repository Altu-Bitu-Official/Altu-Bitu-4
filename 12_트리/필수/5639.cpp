#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;

// left -> right -> root
void postOrder(int first, int last) {

    if(first == last - 1) { // 출력할 노드가 하나밖에 없으면
        cout << tree[first] << '\n'; // 루트 출력
        return;
    }
    else if (first >= last) {
        return;  // 범위를 벗어났으므로 리턴
    }

    int right = -1; // 오른쪽 서브 트리의 루트

    for(int i = first + 1; i <= last; i++) {
        if(tree[i] > tree[first]) { // 현재 루트보다 큰 수가 올 때 저장
            right = i; 
            break;
        }
    }

    if(right == -1) { // 저장된 오른쪽 서브 트리가 없다면
        postOrder(first + 1, last); // left 출력
        cout << tree[first] << '\n'; // 루트 출력
        return;
    }

    // 후위 순회 순서: left -> right -> root
    postOrder(first + 1, right); // left 출력
    postOrder(right, last);      // right 출력
    cout << tree[first] << '\n'; // 루트 출력
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL); 
    cout.tie(NULL);
    
    int v;                                             
    while(cin >> v) {
        tree.push_back(v); // 전위 순회 순서로 저장
    }

    // 후위 순회 순서로 출력
    postOrder(0, tree.size()); 

    return 0;
}