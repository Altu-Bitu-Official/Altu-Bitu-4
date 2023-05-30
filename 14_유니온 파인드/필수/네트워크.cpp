#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) { 
        return node;
    }
    return parent[node] = findParent(parent[node]); 
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x);
    int yp = findParent(y);

    if (xp == yp) {
        return;
    }
    if (parent[xp] < parent[yp]) { 
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else { 
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    parent.assign(n, -1);
    for (int i = 0; i < n; i++) { // 컴퓨터 연결 (같은 네트워크에 속하게 됨)
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1) {
                unionInput(i, j); 
            }
        }
    }
    for (int i = 0; i < n; i++) { // 네트워크의 개수 세기
        if (parent[i] < 0) {
            answer++;
        }
    }
    return answer;
}

/*
* 1. 연결된 컴퓨터를 유니온 연산을 통해 같은 네트워크 집합으로 묶기
* 2. parent 벡터를 이용하여 네트워크 개수 세기
*/

int main() {
    int n = 3;
    vector<vector<int>> computers = {{1, 1, 0}, 
                                     {1, 1, 0}, 
                                     {0, 0, 1}};
    cout << solution(n, computers) << '\n';
    return 0;
}