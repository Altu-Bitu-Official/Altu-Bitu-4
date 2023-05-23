#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;//연결되어야 하니까 포인터
    Node* right;
};

Node* insert(Node* node, int data) {
    if (node == NULL) {//타고타고 비어있을 때만 새로생성
        node = new Node();
        node->data = data;
        node->left = node->right = NULL;
    }
    else if (data <= node->data)
        node->left = insert(node->left, data);
    else
        node->right = insert(node->right, data);
    return node;
}

void postorder(Node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Node* root = NULL;//포인터: 연결위해
    int x;
    while (cin >> x) {//입력받고
        root = insert(root, x);//insert
    }
    postorder(root);//루트노드만 알면 된다. 
}
