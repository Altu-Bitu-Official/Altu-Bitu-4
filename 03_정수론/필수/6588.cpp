#include <iostream>
#include <vector>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<bool> is_prime(1000001, true); //에라토스테네스의 체
    is_prime[0] = is_prime[1] = false;
    for(int i=0; i*i<1000000 ; i++){
        if(is_prime[i]){
            for(int j=i*i; j<=1000000; j+=i){
                is_prime[j] = false;
            }
        }
    }

    while(true){
        int input;
        int a;
        cin >> input;

        if(input == 0){
            break;
        }

        for(int i=3; i<=input/2; i+=2){ 
            if (is_prime[i] && is_prime[input-i]){
                a = i;
                break;
            }
            a = i;
        }

        cout << input << " = " << a << " + " << input-a << '\n';

        //반복문 동안 쌍이 찾아지지 않았을 경우
        if((a+2) > input){
            cout << "Goldbach's conjecture is wrong.";
        }
    }
    return 0;
}
