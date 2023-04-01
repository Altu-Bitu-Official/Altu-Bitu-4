#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    //부모 노드 x, 자식 노드 y
    bool operator()(const int &x, const int &y) {
        //절댓값 다르면 부모 노드 절댓값이 자식 노드 절댓값보다 작아야 함
        if(abs(x)!=abs(y)) {
            return abs(x)>abs(y);
        }
        //절댓값 같으면 부모 노드 값이 자식 노드보다 작아야 함
        //부모 노드가 자식 노드보다 크면 true -> 자리 바꿈
        return x>y;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, tmp;
    cin >> n;

    priority_queue<int, vector<int>, cmp> q;

    for(int i=0; i<n; i++) {
        cin >> tmp;
        if(tmp==0) {
            if(q.empty()) {
                cout << 0 << "\n";
            } else {
                cout << q.top() << "\n";
                q.pop();
            }
        } else {
            q.push(tmp);
        }
    }

    return 0;
}