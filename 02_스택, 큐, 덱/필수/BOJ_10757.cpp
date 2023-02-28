#include <iostream>
#include <string>
using namespace std;

int main() {
    //입력-int형으로 계산x, 문자열 
    string a, b, result;
    cin >> a >> b;
    
    //자릿수 맞춰주기
    if (a.size() > b.size())
    {
        string c;
        for (int i = 0; i < a.size() - b.size(); i++)
            c += '0';
        b = c + b;
    }
    else
    {
        string c;
        for (int i = 0; i < b.size() - a.size(); i++)
            c += '0';
        a = c + a;
    }
    
    //뒤에서부터 연산
    int carry = 0;
    while (a.size() != 0 && b.size() != 0){
        int a_back = a.back() - '0'; 
        int b_back = b.back() - '0'; 
        //a,b의 가장 마지막 자리 a_back, b_back
        
        int r = (carry + a_back + b_back) % 10;
        //나머지
        
        carry = (carry + a_back + b_back) / 10; 
        //올림수 carry
        
        result = (char)(r + '0') + result; 
        a.pop_back();
        b.pop_back();
    }
    
    if (carry) 
        result = (char)(carry + '0') + result;
    
    cout << result << endl;
    return 0;

}