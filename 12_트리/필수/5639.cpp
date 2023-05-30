// 5639 이진 검색 트리
#include <iostream>
#include <map>

using namespace std;
typedef pair<char,char> ci;
map<char, ci> tree; // key, value

void preOrder(char c)
{
    if(c == '.')
    {
        return;
    }
    cout << c;
    preOrder(tree[c].first);
    preOrder(tree[c].second);
}



void inOrder(char c) {
    if (c == '.') {
        return;
    }

    inOrder(tree[c].first);
    cout << c;
    inOrder(tree[c].second);
}

// 후위 순회
void postOrder(char c) {
    if (c == '.') {
        return;
    }

    postOrder(tree[c].first);
    postOrder(tree[c].second);
    cout << c;
}



int main(){
    int N;
    char root, left, right;

    cin >> N;
    while(N--)
    {
        cin >> root >> left >> right;
        tree[root]= make_pair(left, right);
    }

    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
    cout << "\n";
}