#include <iostream>
#include <algorithm>
using namespace std;
#include <iostream>
#include <algorithm>
using namespace std;


string strAdd(string l,string s){// 문자열 두개 더하는 함수
    reverse(l.begin(),l.end()); // 일의 자리부터 비교하며 더하기 위해 문자열 reverse
    reverse(s.begin(),s.end());
    int tmp,carry=0;  //tmp는 두 수를 더했을 때의 값, carry는 올림수
    string v; // 결과값
    for(int i=0;i<s.length();i++){ //일의자리 부터 더하기
        tmp=(l[i]-'0')+(s[i]-'0')+carry; // char to int 위해 '0' 빼줌

        carry=tmp/10; //carry 값 계산
        tmp%=10;

        v.push_back((char)(tmp+48)); //계산 결과 int to char 하여 v에 push
    }
    if(l.length()!=s.length()){ // 두 문자열의 길이가 다르다면 ( l이 s보다 긴 문자열이라면)
        for(int i=s.length();i<l.length();i++){ //l의 남은 부분을 v에 push
            tmp=(l[i]-'0')+carry;
            v.push_back((char)((tmp)%10+48));
            carry=tmp/10;
        }
    }
    if(carry>0){
        v.push_back((char)(carry+48));  //carry값이 남아있다면 v에 push

    }

    reverse(v.begin(),v.end()); // 일의 자리가 인덱스 0에 위치해 있으므로 결과 string v reverse해주어야함

    return v;

}
int main() {
    string a,b;

    cin >> a >> b;

    if(a.length()<=b.length()){
        cout << strAdd(b,a);
    }else{
        cout <<strAdd(a,b);
    }

    return 0;
}


