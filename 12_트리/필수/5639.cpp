#include <iostream>
#include <vector>

using namespace std;

void postOrder(vector<int>  pre_order) {
    if (pre_order.empty()) return;
    int root = pre_order[0];
    vector<int> left, right;
    for (int i = 1; i < pre_order.size(); i++) {
        if (pre_order[i] < root) left.push_back(pre_order[i]);
        else right.push_back(pre_order[i]);
    }
    postOrder(left);
    postOrder(right);
    cout << root << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> pre_order;
    int x;
    while (cin >> x) {
        pre_order.push_back(x);
    }
    postOrder(pre_order);
    return 0;
}
