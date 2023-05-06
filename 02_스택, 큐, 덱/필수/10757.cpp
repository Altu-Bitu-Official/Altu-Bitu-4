#include <iostream>
#include <vector>

using namespace std;

int main (){

    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string As;
    string Bs; //큰 수 두개를 문자열로 입력받기

    int length; //큰 수 길이

    cin >> As >> Bs;

    if(As.length()>=Bs.length()){ //둘 중 더 긴 수의 길이를 length로 저장
        length = As.length();
    }
    else{
        length = Bs.length();
    }

    int l= length;

    int carry=0;
    vector<int> result(length+1);

    int length_a = As.length();
    int length_b = Bs.length();

    while((length_a>0)&&(length_b>0)){
        result[length--] = ((As[--length_a]-'0')+(Bs[--length_b]-'0')+carry)%10;
        carry = ((As[length_a]-'0')+(Bs[length_b]-'0')+carry)/10;
    }

    while(length_a>0){
        result[length--] = ((As[--length_a]-'0')+carry)%10;
        carry = ((As[length_a]-'0')+carry)/10;
    }
    while(length_b>0){
        result[length--] = ((Bs[--length_b]-'0')+carry)%10;
        carry = ((Bs[length_a]-'0')+carry)/10;
    }

    if(carry !=0){
        result[length--]=carry;
    }

    for(int i=length+1; i<l+1; i++){
        cout << result[i];
        
    }
    return 0;

}
