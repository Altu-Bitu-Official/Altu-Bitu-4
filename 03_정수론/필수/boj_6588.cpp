#include <iostream>
#include <vector> 

const int SIZE =1000000;

using namespace std; 


vector <bool> findPrime(int n){
    vector <bool> prime(n+1, true);
   
    prime[0]= prime[1] = false; 

    for(int i =2; i *i <n; i++){
        if(prime[i]== true){
            //i가 소수이면 
            for(int j = i*i; j <=n; j += i){ // i의 배수들 지우기 
                prime[j] = false;
            }
        }
    }

    return prime;
}


int main () {

    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    int n;
    vector <bool> prime = findPrime(SIZE);

    //입력 & 출력 
    while (1){
        cin >> n ; 
        if(n == 0) {
            break;
        }
        bool check = false;  // 계산할 수 없는 경우 메세지 출력을 위해 

        for (int a = 3; a <= n/2 + 1; a +=2 ){
          if(prime[a] == true && prime[n-a] == true){
              cout<<n<<" = "<<a<<" + "<<n-a<<"\n";
              check = true;
              break;
             }
        }
        if(check ==false){  // 계산 불가한 경우 메세지 출력 
           cout << "Goldbach's conjecture is wrong.\n";
            break;
       }
        
     }
  
    return 0;
}
