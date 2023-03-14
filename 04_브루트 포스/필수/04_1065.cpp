#include <iostream>

using namespace std;

int main() {
    int n;
    int count = 0;
    int h, t, o;
    cin >> n;

        if(n<100){
            cout << n;
        }
        else{
            for(int i=100; i<=n; i++){
                h = i/100;
                t = (i/10) - ((i/100)*10);
                o = i%10;
                if((h-t)==(t-o)){
                    count++;
                }
            }
            cout << count + 99 <<endl;
        }
    return 0;
}
