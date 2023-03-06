#include <iostream>
#include <algorithm>


using namespace std; 

// 최대 공약수 구하는 함수 
int GCD (int a, int b){
    if(b>a){
        return GCD(b,a);
    }
    if (a % b == 0 ){
        return b;
    } 
    else return GCD(b , a % b);
}


int main(){

    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);


    int up1, down1, up2, down2, r_up, r_down;  //분자 분모를 각각 up, down 에 대입, 계산을 마치고 최종 분자 분모를 r_up, r_down에 대입 
    //입력
    cin >> up1 >> down1 >> up2 >> down2 ;

    r_up = up1 * down2 + up2 * down1;  //분자 계산
    r_down = down1 * down2;            // 분모 계산 
    //출력
    cout << r_up/ GCD(r_up,r_down) << ' '<< r_down/GCD(r_up,r_down);  

   
   

     

    return 0;
}