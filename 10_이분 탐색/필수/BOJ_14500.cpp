#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//n과 m, 칸 별 수가 담긴 배열 num을 받아 I미노를 사용할 경우의 최대값을 계산해 리턴하는 함수
int iMino(int n, int m, vector<vector<int>>& num) {
    int max_sum = 0;
    int partial_sum;
    //세로 1, 가로 4
    int d[4] = {0, 1, 2, 3};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 3; j++) {
            partial_sum = 0;
            for (int k = 0; k < 4; k++) {
                partial_sum += num[i][j + d[k]];
            }
            max_sum = max(max_sum, partial_sum);
        }
    }
    //세로 4, 가로 1

    for (int i = 0; i < n - 3; i++) {
        for (int j = 0; j < m; j++) {
            partial_sum = 0;
            for (int k = 0; k < 4; k++) {
                partial_sum += num[i + d[k]][j];
            }
            max_sum = max(max_sum, partial_sum);
        }
    }
    return max_sum;
}
//n과 m, 칸 별 수가 담긴 배열 num을 받아 O미노를 사용할 경우의 최대값을 계산해 리턴하는 함수
int oMino(int n, int m, vector<vector<int>>& num) {
    int max_sum = 0;
    int partial_sum;

    //가로 2, 세로 2
    int dx[4] = {0, 0, 1, 1}; int dy[4] = {0, 1, 1, 0};

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m-1; j++) {
            partial_sum = 0;
            for (int k = 0; k < 4; k++) {
                partial_sum += num[i + dx[k]][j + dy[k]];
            }
            max_sum = max(max_sum, partial_sum);
        }
    }
    return max_sum;
}

//n과 m, 칸 별 수가 담긴 배열 num을 받아 L, S, T미노를 사용할 경우의 최대값을 계산해 리턴하는 함수
int lstMino(int n, int m, vector<vector<int>>& num) {
    int max_sum = 0;
    int partial_sum, sub;

    //세로 3, 가로 2 -> L 4개, 나머지 2개이므로 8개

    for (int i = 0; i < n- 2; i++) {
        for (int j = 0; j < m - 1; j++) {
            partial_sum = num[i][j] + num[i+1][j] + num[i+2][j] + num[i][j+1] + num[i+1][j+1] + num[i+2][j+1]; //가로 3, 세로 2인 직사각형을 더함.
            sub = min({num[i][j+1] + num[i+1][j+1], num[i][j] + num[i+1][j], num[i+1][j] + num[i+2][j], num[i+1][j+1] + num[i+2][j+1], num[i][j+1] + num[i+2][j], num[i][j] + num[i+2][j+1], num[i][j+1] + num[i+2][j+1], num[i][j] + num[i+2][j]});  //직사각형에서 두 칸을 빼면 테트리미노가 됨 -> 합이 가장 작은 두 칸 찾기
            max_sum = max(max_sum, partial_sum - sub);  //현재 최댓값과 두 칸을 뺀 값 중 더 큰 값이 최대값으로
        }
    }
    
    //세로 2, 가로 3 -> 마찬가지로 8개

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m-2; j++) {
            partial_sum = num[i][j] + num[i+1][j] + num[i][j+1] + num[i+1][j+1] + num[i][j+2] + num[i+1][j+2];
            sub = min({num[i][j] + num[i][j+1], num[i][j+1] + num[i][j+2], num[i+1][j] + num[i+1][j+1], num[i+1][j+1] + num[i+1][j+2], num[i][j] + num[i+1][j+2], num[i][j+2] + num[i+1][j], num[i+1][j] + num[i+1][j+2], num[i][j] + num[i][j+2]});
            max_sum = max(max_sum, partial_sum - sub);
        }
    }
    return max_sum;
}

//각 미노별 연산값을 수합하여, 최종적으로 최댓값을 구하는 함수.
int calcMax (int n, int m, vector<vector<int>>& num) {
    int max_sum = max({iMino(n, m, num), oMino(n, m, num), lstMino(n, m, num)});
    return max_sum;
}

int main() {
    int n, m;
    vector<vector<int>> num;
    
    //입력
    cin >> n >> m;
    num.assign(n, vector<int> (m, 0));

    for (int i =0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> num[i][j];
        }
    }

    //출력
    cout << calcMax(n, m, num);


}