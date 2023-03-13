#include <iostream>

using namespace std;


int main(){
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);


    int N, i;
    cin >> N;
    int countNum = 0;

    for( i=1; i<=N; i++){

        if(i>=1 && i<100){
            countNum++;
    // 1~99까지는 무조건 등차
        }
        else if (i>=100 && i<1000) {
            int a = i%10;       //1의 자리
            int b = (i/10)%10;  //10의 자리
            int c = (i/100)%10; //100의 자리

            if( 2*b == a+c){
                countNum++;
                // 1000은 등차가 아니므로 고려 자체를 안함
            }
           
        }
    }
    cout << countNum;
    return 0;
}