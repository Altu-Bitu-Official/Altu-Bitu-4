#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string a, b;
    string rslt = "";
    int tmp=0;
    cin >> a >> b;
    int a_len = a.length();
    int b_len = b.length();

    if(a_len > b_len){
        for(int i=0;i<a_len-b_len;i++){
            b = to_string(0)+b;
        }

    }
    else if(b_len > a_len){
        for (int i=0;i<b_len-a_len;i++){
            a = to_string(0)+a;
        }
    }

    int len=a.length()-1;


    for(int i=len;i>=0;i--){
        int n,m,x;

        n=a[i]-'0';
        m=b[i]-'0';

        if(tmp==1){
            x = n+m+1;
        }
        else if(tmp==0){
            x = n+m;
        }
        tmp=0;

        if(x>9){
            tmp = 1;
            rslt +=to_string(x%10);
        }
        else {
            rslt +=to_string(x);
        }
    }


    if(tmp==1){
        rslt += "1";
    }

    reverse(rslt.begin(), rslt.end());
    cout << rslt << "\n";


    return 0;
}