#include <iostream>
#include <vector>
using namespace std;

bool isAns(int n) { //한수 체크 함수
    int b,sub;
    vector<int> digit;

    do {
        b = n % 10;
        n /= 10;
       digit.push_back(b);
    } while (n); //숫자  n의 각 자릿수 digit 벡터에 삽입하는 do while문

    if(digit.size()==1 || digit.size()==2){ //한자리수와 두자리수는 항상 한수 이므로 true 리턴
        return true;
    }
    int tmp = digit[1]-digit[0]; // 이전 자릿수의 차 저장할 변수
    for(int i=1;i<digit.size()-1;i++){
        sub = digit[i+1]-digit[i]; //현재 자릿수의 차
        if(tmp!=sub){ //이전 자릿수의 차와 현재 자릿수의 차가 다를 경우 false 리턴
            return false;
        }
        tmp =sub;
    }
    return true; //정상적으로 다 돌 경우 true 리턴
}

int main(){

    int n,ans=0; //입력받을 숫자 n, 정답 저장할 변수 ans
    cin >> n;

    for(int i=1;i<=n;i++){ //입력받은 숫자까지 한수인지 체크
        if(isAns(i)){
            ans++;
        }
    }
    cout << ans;

    return 0;
}