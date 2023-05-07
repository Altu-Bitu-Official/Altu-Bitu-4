// 한수

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{   
    int cnt = 0, n, ans;
    cin >> n;
    for (int i=1; i<=n; i++){
        if (i<=99) // 두 자리수까지는 항상 한수
            cnt++;
        else{
            int d = ((i/10)%10) - i%10; // 공차
            ans = 0; // 한수인지 확인변수 초기화
            for (int j = 0; j<to_string(i).size()-2; j++){
                if (((i/int(pow(10,j+2)))%10)-((i/int(pow(10,j+1)))%10) != d){ // 공차가 다르면
                    ans = 1; // 한수가 아님
                    break;
                }
            }
            if (ans == 0)
                cnt++;
        }
    }
    cout << cnt;
    return 0;       
}