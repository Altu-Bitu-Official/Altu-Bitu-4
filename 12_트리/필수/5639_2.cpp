// 트리와 쿼리
#include <iostream>
#include <vector>
using namespace std;

void postorder(int start, int end, vector<int> &node){
    if (start >= end){ // 재귀 종료조건
        return;
    }
    int i;
    for (i = start+1; i < end; i++){
        if (node[start] < node[i]){ // 루트보다 더 큰값이 나오면 종료
            break;
        }
    }
    postorder(start+1, i, node); // 왼쪽 서브트리 순회
    postorder(i, end, node); // 오른쪽 서브트리 순회
    cout << node[start] << '\n'; // 루트노드 출력
}

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int x, idx = 0;
    vector<int> node(10000,0);
    
    while (cin >> x){
        node[idx++] = x;
    }
    postorder(0, idx, node);
    return 0;
}