#include <iostream>
#include <string>

using namespace std;

int check(int n){
    int num = 665;

    //N번째 영화
    while(n--){
        bool c = true;
        while(c){
            int sum = 0;
            //도달할 때까지 +1
            string str = to_string(++num);
            //끝의 2개 제외
            for(int i=0; i<=str.length()-3; i++){
                //연속해서 6이 3번 나오면 반복문 중지
                if(str[i] == '6' && str[i+1] == '6' && str[i+2] == '6'){
                    c = false;
                }
            }
        }
    }
    return num;
}

int main()
{
    int n;
    //입력
    cin >> n;
    //검사
    int num = check(n);
    //출력
    cout << num;
}