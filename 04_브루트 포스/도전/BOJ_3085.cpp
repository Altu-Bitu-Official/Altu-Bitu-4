#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cnt_nochange;

int countMax(vector<vector<char>> candy) {
    int n = candy[0].size(), max_cnt = 0;
    for (int i = 0; i < n; i++) {
        int cnt_w = 1, cnt_h = 1;
        for (int j = 0; j < n - 1; j++) {
            if (candy[i][j] == candy[i][j + 1]) {
                cnt_w++;
            }
            else {
                max_cnt = max(max_cnt, cnt_w);
                cnt_w = 1;
            }
            if (candy[j][i] == candy[j + 1][i]) {
                cnt_h++;
            }
            else {
                max_cnt = max(max_cnt, cnt_h);
                cnt_h = 1;
            }
        }
        max_cnt = max(max_cnt, cnt_w);
        max_cnt = max(max_cnt, cnt_h);
    }

    return max_cnt;
}

int swapCandyW(vector<vector<char>> candy, int i, int j, int k) {
    if (candy[i][j] == candy[i][k]) {
        return cnt_nochange;
    }

    swap(candy[i][j], candy[i][k]);
    return countMax(candy);

}

int swapCandyH(vector<vector<char>> candy, int i, int j, int k) {
    if (candy[j][i] == candy[k][i]) {
        return cnt_nochange;
    }

    swap(candy[j][i], candy[k][i]);
    return countMax(candy);

}

int main() {
    int n, max_cnt = 0;
    vector<vector<char>> candy;
    cin >> n;
    candy.assign(n, vector<char>(n, ' '));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> candy[i][j];
        }
    }

    cnt_nochange = countMax(candy);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            max_cnt = max(max_cnt, swapCandyW(candy, i, j, j+1));
            max_cnt = max(max_cnt, swapCandyH(candy, i, j, j+1));
        }
    }
    cout << max_cnt;
}