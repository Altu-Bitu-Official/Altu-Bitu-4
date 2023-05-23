#include<iostream>
#include<cstdio>
using namespace std;

struct node {
	int data;
	node* left;
	node* right;
};

node* insert(node* tree, int num) {
	if (tree == NULL) {//루트 노드
		tree = new node();
		tree->data = num;//데이터 삽임
		tree->right = NULL;
		tree->left = NULL;
	}

	else if (num < tree->data) {//부모 보다 작으면 왼쪽에 삽입
		tree->left = insert(tree->left, num);//재귀적으로 호출
	}
	else {//같은 경우는 존재x, 부모보다 크면 오르쪽에 삽입
		tree->right = insert(tree->right, num);

	}
	return tree;
}

void postorder(node* tree) {
	//postorder는 left->right->root 순서이므로 left자식이 있는지 체크하는 if문이 먼저옴
	if (tree->left !=NULL) {//왼쪽 자식이 존재한다면
		postorder(tree->left);//왼쪽 자식 호출
	}
	if (tree->right != NULL) {//오른쪽 자식이 존재한다면 호출
		postorder(tree->right);
	}
	cout << tree->data << "\n";//더이상 자식이 없다면 출력, 이후 다시 부모 노드로 돌아옴
}

int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);

	int num = 0;
	node* tree = NULL;
	//입력 및 트리 생성
	while (cin >> num) {
		if (num == EOF) {
			break;
		}
		tree=insert(tree, num);
	}

	//출력
	postorder(tree);

	return 0;
}