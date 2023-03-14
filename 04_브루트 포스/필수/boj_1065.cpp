#include <iostream>

using namespace std;

int isHansoo (int n){
    int count =0;
    int hun, ten, one;

    if (n < 100){
        return n;
    }
        
    else {
        count = 99;       //2자리 자연수는 모두 한수이니까 100까지는 99개의 한수가 있음

        for (int i =100; i <= n; i++){
                
            hun = i / 100;     //첫번째 자릿수
            ten = (i % 100) / 10 ; //두번째 자릿수
            one = i % 10;      //세번째 자릿수
            
            if ((hun - ten) == (ten - one))  //등차수열이면
            {
                count++;
            } 
        }
        return count;
     }
        
    
 }
    
   





int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    //입력
    int n; 
    cin >> n;
    
    //출력
    cout << isHansoo (n);

    return 0;
}