#include <iostream>

using namespace std;

bool isSequence(int n) {
    string tmp = to_string(n);

    //한자리 숫자는 무조건 등차수열이므로 true 반환
    if(tmp.size()==1) {
        return true;
    }

    //처음 두 숫자 차이 변수에 저장하고
    int diff = tmp[1]-tmp[0];
    //다음 두 숫자 차이 변수값과 똑같은지 계속 돌면서 확인
    for(int i=1; i<tmp.size()-1; i++){
        //다르면 바로 false 반환
        if(diff!=(tmp[i+1]-tmp[i])) {
            return false;
        }
    }
    //다 돌았으면 등차수열 맞으므로 true 반환
    return true;
}

int main() {
    int n;
    int cnt=0;
    cin >> n;

    for(int i=1; i<=n; i++) {
        if(isSequence(i)) {
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}