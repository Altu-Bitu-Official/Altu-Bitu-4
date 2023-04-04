#include <iostream>
#include <vector>

using namespace std;

//입력받은 배열을 받아 최소 속도를 계산해 리턴하는 함수
long long calcMinimumSpeed(vector<long long>& input) {
    long long minimum_v = 0;

    for (long long i : input) {
        if (i > minimum_v) {    //최소 속도보다 i가 클 때
            minimum_v = i;  //최소 속도에 대입
        }
        else {
            minimum_v = ((minimum_v-1)/i + 1) * i;  //최소 속도보다 큰 i의 배수 중 가장 작은 값을 최소 속도에 대입 
        }
    }

    return minimum_v;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    vector<long long> input;
    cin >> n;
    input.assign(n, 0);

    //입력 : 뒤에서부터 검사하기 위해 거꾸로 받음
    for (int i = n-1; i >= 0; i--) {
        cin >> input[i];
    }

    //출력
    cout << calcMinimumSpeed(input);
}