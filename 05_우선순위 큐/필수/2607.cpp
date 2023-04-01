#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    int **arr = new int *[n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[26];
        for (int j = 0; j < 26; j++) {
            arr[i][j] = 0;
        }
    }


    //입력
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            arr[i][(int)str[j]-65]++;
        }
    }

    //비교
    int count = 0;
    for (int i = 1; i < n; i++) {
        int check1 = 0, check2 = 0;
        for (int j = 0; j < 26; j++) {

            if (arr[i][j] - arr[0][j] == 1) {
                check1++;
                check2++;
            } else if (arr[i][j] - arr[0][j] == -1) {
                check1--;
                check2++;
            } else if (arr[i][j] - arr[0][j] > 1) {
                check1 = 100;
                break;
            }

            if (abs(check1) > 1 || check2 > 2) {
                break;
            }
        }

        if (abs(check1) <= 1 && check2 <= 2) {
            count++;
        }
    }

    cout << count;
}