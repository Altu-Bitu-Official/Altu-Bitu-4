#include <iostream>

using namespace std;
 
int gcd(int n1, int n2){
    if (n2%n1 == 0){
        return n1;
    }
    else
        gcd(n2%n1, n1);
}
 
int main(void){

    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int denom1, numer1, denom2, numer2;
    cin >> numer1>> denom1>> numer2>> denom2;

    int gcdNum = gcd(denom1, denom2);
 
    int resultDenom = denom1*denom2 / gcdNum;
    int resultNumer = resultDenom / denom1 *numer1 + resultDenom/ denom2*numer2;
 
    gcdNum = gcd(resultDenom, resultNumer);
 
 
 
    cout<<resultDenom/gcdNum<< " "<<resultNumer/gcdNum;
    return 0;
}
