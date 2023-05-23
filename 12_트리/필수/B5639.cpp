#include <iostream>
#include <vector>
using namespace std;
// 전위 순회 -> 트리 생성 -> 후위 순회 출력

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int key) { // 초기화
        value = key;
        left = nullptr;
        right = nullptr;
    }
};
// 이진검색트리 특징에 맞게 노드 삽입
Node* insert(Node* root, int value) {
    if (root == nullptr) { 
        return new Node(value); // 새로운 노드 생성 
    }
    else if (value < root->value) {
        root->left = insert(root->left, value); // 왼쪽 서브 트리에 삽입
    }
    else {
        root->right = insert(root->right, value); // 오른쪽 서브 트리에 삽입
    }
    return root;
}

Node* Make_Tree(vector <int> &preorder) { // 이진 검색 트리 생성
    int size = preorder.size();
    Node* root = nullptr;
    for (int i = 0; i < size; i++) {
        root = insert(root, preorder[i]);
    }
    return root;
}

void post_order(Node* node) { // 후위 순회로 출력  (L - R - V)
    if (node != nullptr) {
        post_order(node->left);
        post_order(node->right);
        cout << node->value << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    vector <int> preorder;
    int n;
    while (cin >> n) { // 노드의 키 값은 양의 정수이므로
        if (n == 0) break; // 종료 조건을  0 입력으로 설정
        preorder.push_back(n);
    }
    Node* root = Make_Tree(preorder);

    post_order(root);
    return 0;
}
