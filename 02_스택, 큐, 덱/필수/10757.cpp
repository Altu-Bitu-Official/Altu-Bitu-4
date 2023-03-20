//
// Created by dduoy on 2023-02-28.
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string add(string &a, string &b){
    string res(max(a.size(), b.size()),'0');
    bool carry = false;

    for(int i=0; i<res.size(); i++){
        int tmp = carry;
        carry = false;

        if(i < a.size()){
            tmp += a[a.size()-i-1] - '0';
        }
        if(i < b.size())
            tmp += b[b.size()-i-1] - '0';
        if(tmp>=10){
            carry = true;
            tmp -= 10;
        }

        res[res.size()-i-1]=tmp+'0';
    }
    if(carry){
        res.insert(res.begin(),'1');
    }
    return res;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    string a,b;
    cin >> a >> b;
    cout << add(a,b);
    return 0;
}