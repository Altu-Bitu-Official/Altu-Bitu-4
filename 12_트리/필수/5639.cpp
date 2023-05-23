#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, pair<int, int>> tree;//맵으로 한다. 본인,자식노드들

// 후위 순회 왼-오-중간
void postorder(int v) {
    if (v == 0) {
        return;
    }

    postorder(tree[v].first);//왼쪽
    postorder(tree[v].second);//오른쪽
    if (v != 0)
    {
        cout << v;//가운데
    }
}

int main() {

    char root, left, right;
    int n = 0;
    vector<int> number;
    // 입력
    while (cin >> n) {
        number.push_back(n);
    }
    for (int j = 0; j < (number.size() - 1); j++) {
        left = 0, right = 0;//0이면 비었다는 뜻
        if (number[j] < number[j + 1]) {//루트보다 크면 오른쪽으로
            right = number[j + 1];
        }
        if (number[j] > number[j + 1]) {
            left = number[j + 1];
        }
        tree[number[j]] = { left,right };
    }

    // 연산 + 출력
    postorder(number[0]);//루트 넣기
    return 0;
}