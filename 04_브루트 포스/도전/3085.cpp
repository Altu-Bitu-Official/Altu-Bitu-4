#include <iostream>
#include <vector>

using namespace std;

int getCount(vector<vector<char> > candy, int n) {
    int result=0;
    int cnt;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            //비교할 사탕 색 변수에 저장
            char tmp = candy[i][j];
            //세로 연속 개수
            cnt = 1;
            for(int k=i+1; k<n; k++) {
                if(tmp==candy[k][j]) {
                    cnt++;
                } else {
                    break;
                }
            }
            result = max(result, cnt);
            //가로 연속 개수
            cnt = 1;
            for(int k=j+1; k<n; k++) {
                if(tmp==candy[i][k]) {
                    cnt++;
                } else {
                    break;
                }
            }
            result = max(result, cnt);
        }
    }

    return result;
}

int main() {
    int n;
    int result=0;
    cin >> n;

    vector<vector<char> > candy(n, vector<char> (n));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> candy[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            //가로로 인접하고 색깔 다른 두 사탕 선택해서 바꿈
            if(i+1<n && candy[i][j]!=candy[i+1][j]) {
                swap(candy[i][j], candy[i+1][j]);
                result = max(result, getCount(candy, n));
                //다시 돌려놓기
                swap(candy[i][j], candy[i+1][j]);
            }


            //세로로 인접하고 색깔 다른 두 사탕 선택해서 바꿈
            if(j+1<n && candy[i][j]!=candy[i][j+1]) {
                swap(candy[i][j], candy[i][j+1]);
                result = max(result, getCount(candy, n));
                //다시 돌려놓기
                swap(candy[i][j], candy[i][j+1]);
            }
        }
    }

    cout << result;

    return 0;
}