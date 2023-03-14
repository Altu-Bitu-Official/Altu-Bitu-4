#include <iostream>

using namespace std;

int main() {
    // 입력 및 연산
    int n, k;
    cin >> n >> k;
    char *arr = new char[n];
    int dup[26]; //알파벳 중복 사용 체크
    bool check = true;

    int num = 0;
    char alp;
    for(int & i : dup){
        i = -1;
    }

    for (int i = 0; i < k; i++) {
        //바퀴 어느 칸에 저장할 지 결정
        int index;
        cin >> index >> alp;
        num += index;
        if (num >= n) {
            num %= n;
        }

        //예외 1. 한 알파벳이 여러 개의 칸에 저장될 경우
        if (dup[alp - 65] != -1 && dup[alp - 65] != num) {
            for (int j = 0; j < n; j++) {
                arr[j] = '!';
            }
            check = false;
        }

        //예외 2. 이미 결정된 칸에 새로운 알파벳을 저장하는 경우
        else if ((arr[num] && arr[num] != alp)) {
            for (int j = 0; j < n; j++) {
                arr[j] = '!';
            }
            check = false;
        }

        // 그 외 정상적으로 알파벳을 저장하는 경우
        arr[num] = alp; //알파벳 기록
        dup[alp - 65] = num; //알파벳이 저장된 칸을 기록
    }

    //출력
    //예외 1, 2 중 하나에 걸렸을 경우
    if(!check){
        cout << "!";
    }

    else{
        for (int i = 0; i < n; i++) {
            if (arr[num]) {
                cout << arr[num];
            } else {
                cout << "?";
            }

            num--;

            if (num < 0) {
                num = n - 1;
            }
        }
    }

    delete[]arr;
    return 0;
}