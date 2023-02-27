#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void calculate(const string& str, int& sum){
    for(char i:str){
        if(i >= '0' && i <= '9')  
            sum += i-48;          //0의 아스키코드는 48
    }
}

bool sortGuitar(const string& a, const string& b){
    if(a.length() == b.length()){
        int sum_a = 0;
        int sum_b = 0;
        //합을 계산하는 함수
        calculate(a, sum_a);
        calculate(b, sum_b);

        /*@@@질문입니다!! -> 이해했어요. 감사합니다(ㅠㅠS2)

        for(char i:a){
            if(i >= '1' && i <= '9')  
                sum_a += i;  
        }
        for(char i:b){
            if(i >= '0' && i <= '9')     
                sum_b += i-48;
        }

        25~32번줄 대신 위의 코드로 풀면 왜 답이 안 나오는지,,^_^ 궁금합니다.
        0(아스키코드로 48)을 제외하고 더해도 (어차피 '0'은 0으로, 더하지 않아도 값이 달라지지 않으니)
        괜찮다고 생각했는데 답이 틀렸다고 나와서요!!

        A) 반례
        2
        145C = 49+53+52 = 154
        A910 = 57+49+(0 제외) = 106
        */

        if(sum_a != sum_b)
            return sum_a < sum_b;        //작은 순 대로 정렬
        //A의 모든 자리수의 합과 B의 모든 자리수의 합이 같을 때
        return a < b;
    }
    else   //A와 B의 길이가 다르면, 짧은 것이 먼저 온다.
    {
        return a.length() < b.length();
    }
}

int main(void){
    int n;
    cin >> n;
    vector<string> number;
    //시리얼 번호 입력 받기
    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        number.push_back(str);
    }
    //정렬
    sort(number.begin(), number.end(), sortGuitar);
    //출력
    for(int i=0; i<n; i++)
        cout << number[i] << "\n";
}