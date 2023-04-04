#include <iostream>

using namespace std;

string solution(string number, int k) {
    string str=number;

    for(int i=1; i<str.size(); i++) {
        //뒤 숫자가 잎 숫자보다 크면 앞 숫자 제거
        while(k>0 && str[i]>str[i-1] && i>0 ) {
            str.erase(str.begin()+i-1);
            i--;
            k--;
        }
    }

    //앞 숫자보다 작은 뒤 숫자 전부 제거해도 제거 횟수 남았으면 맨 뒤부터 제거
    while(k>0) {
        str.erase(str.end()-k);
        k--;
    }

    return str;
}

int main() {
    string number="4321";
    int k=1;

    cout << solution(number, k);

    return 0;
}