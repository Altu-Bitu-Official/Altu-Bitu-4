#include <iostream>
#include <vector>

using namespace std;
//전위순회 루트 왼쪽 오른쪽
vector<int> preorder;

//후위 순회 함수 왼쪽 오른쪽 루트
void postorder(int start, int end) {
    if (start > end)
        return;

    int idx = start + 1;
    
    while (idx <= end && preorder[idx] < preorder[start])
    {
        idx++;
    }

    //후위 순회 
    postorder(start + 1, idx - 1);
    postorder(idx, end);
    cout << preorder[start] << "\n";
}

int main() {
    
    int value;
    while (cin >> value)
    {
        preorder.push_back(value);
    }

    postorder(0, preorder.size() - 1);
    
    return 0;
}