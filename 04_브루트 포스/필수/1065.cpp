#include <iostream>

using namespace std;

int check (int num){ //각 자리수가 등차수열을 이루는지 확인
    int d;
    d = ((num%100)/10) - (num%10);
    while(num>=10){
        num /= 10;
        if(d != ((num%100)/10) - (num%10)){
            break;
        }
    }

    if(num<10){
        return 1;
    }

    return 0;
}
int main(){
    int n;
    int num = 0;
    int count = 0;

    cin >> n;

    for(int i=0; i<n; i++){
        num++;
        count += check(num); //등차수열을 이룰 경우 count+1

    }
    cout << count;

    return 0;
}