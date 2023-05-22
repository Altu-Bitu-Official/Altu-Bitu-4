#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int key;
  Node *left;
  Node *right;
  int child = 0;
};

void insert_node(Node **node, int key) {
  Node *parent, *current;
  Node *new_node;
  current = *node;
  parent = NULL;

  while (current != NULL) {
    if (key == current->key) {
      return;
    }
    parent = current;
    if (key < current->key) {
      current = current->left;
    } else {
      current = current->right;
    }
  }
  new_node = (Node *)malloc(sizeof(Node));
  if (new_node == NULL) {
    return;
  }
  new_node->key = key;
  new_node->left = new_node->right = NULL;

  if (parent != NULL) {
    if (key < parent->key) {
      parent->left = new_node;
    } else {
      parent->right = new_node;
    }
  } else {
    *node = new_node;
  }
}

void postorder(Node *root) {
  if (root->left)
    postorder(root->left);
  if (root->right)
    postorder(root->right);
  if(root->key != 0)
    cout << root->key << '\n';
}

int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(NULL);

  int key;
  Node *root = (Node *)malloc(sizeof(Node));

  while (cin >> key) {
    if (cin.eof()) {
      break;
    }
    insert_node(&root, key);
  }
  postorder(root);
  return 0;
}