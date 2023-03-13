#include <iostream>
#include <math.h>

using namespace std;

int check (int title){ //연속된 세개의 6이 있는지 확인
    while(title>600){
        if(title%1000 == 666){
            return 1;
        }
        title /= 10;
    }
    return 0;
}

int main(){

    int n;
    cin >> n;

    int title = 666;
    int count = 1;

    while (1){

        if(count == n){
            break;
        }

        title ++;

        count += check(title); //연속된 세개의 6이 있을 경우 count+1

    }
    cout << title;

    return 0;
}