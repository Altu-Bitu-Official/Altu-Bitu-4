#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

void isPrime(vector<int>& prime){
    //소수라면 1, 소수가 아니라면 0
    for(int i=2; i*i<=MAX; i++){
        if(prime[i] ==1){
            //i가 소수라면
            for(int j = i*i; j<=MAX; j+=i){
                prime[j] = 0;   //소수가 아닌 수 0으로 바꾸기
            }
        }
    }
}

int calculate(const int n, vector<int>& prime){
    for(int i=3; i<=n/2; i++){
        //i가 소수고, n-i도 소수면 해당함
        if(prime[i] == 1 && prime[n-i] == 1){
            return i;
        }
    }
    //찾지 못했다면
    return -1;
}

int main()
{
    //입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //1로 초기화
    vector<int> prime(MAX, 1);

    //에라토스테네스의 체
    isPrime(prime);

    while(true){
        int n;
        cin >> n;
        //프로그램 종료
        if(n == 0){
            return 0;
        }
        //골드바흐의 추측 계산
        int num = calculate(n, prime);  

        //출력
        if(num > 0){
            cout << n << " = " << num << " + " << n-num << "\n";
        }
        else{
            cout << "Goldbach's conjecture is wrong.\n";
        }
    }
}