#include <iostream>
#include <map>

using namespace std;

map<char,pair<char,char>> tree; // char 형의 키 와  pair <char, char> 의 값
//char형의 키는 트리의 노드를 식별하는 데 사용되며, pair<char,char>형의 값은 해당 노드의 왼쪽 자식 노드와 오른쪽 자식 노드의 값을 저장하는 역할을 합니다.
void preorder(char v)
{
    if(v == '.')
    {
        return;
    }
    cout << v;
    preorder(tree[v].first);
    preorder(tree[v].second);
}


// 중위 순회 L - V - R
void inorder(char v) {
    if (v == '.') {
        return;
    }

    inorder(tree[v].first);
    cout << v;
    inorder(tree[v].second);
}

// 후위 순회 L - R - V
void postorder(char v) {
    if (v == '.') {
        return;
    }

    postorder(tree[v].first);
    postorder(tree[v].second);
    cout << v;
}



int main(){
    int n;
    char root, left, right;

    cin >> n;
    while(n--)
    {
        cin >> root>> left>> right;
        tree[root]= {left,right};
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';
    return 0;
}