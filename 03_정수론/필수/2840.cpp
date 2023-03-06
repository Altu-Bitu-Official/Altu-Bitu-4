#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    int turn;
    char alphabet;
    int tmp = 0;

    cin >> n >> k;

    vector<char> wheel(n);

    for(int i=0; i<k; i++) {
        cin >> turn >> alphabet;
        //이동 칸수 누적합 변수에 저장
        tmp += turn;
        //원형 바퀴니까 이동한 칸 수를 칸 수로 나눈 나머지를 인덱스로 사용
        if(wheel[tmp%n] && wheel[tmp%n]!=alphabet) {
            //이미 값이 적힌 칸에 들어갈 값이 다르면 모순 ! 출력
            cout << '!';
            return 0;
        } else {
            wheel[tmp%n]=alphabet;
        }
    }

    //동일한 알파벳 두 번 이상 나오면 모순 ! 출력
    for(int i=0; i<wheel.size(); i++) {
        for(int j=i+1; j<wheel.size(); j++) {
            if(wheel[i] && wheel[j] && wheel[i]==wheel[j]) {
                cout << '!';
                return 0;
            }
        }
    }

    for(int i=0; i<wheel.size(); i++) {
        //화살표가 마지막으로 가리킨 칸(=tmp)에서 인덱스 1씩 줄이며 출력
        if(wheel[(tmp-i)%n]) {
            cout << wheel[(tmp-i)%n];
        } else {
            cout << '?';
        }
    }

    return 0;
}