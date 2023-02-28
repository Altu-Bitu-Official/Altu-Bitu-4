//
// Created by LG on 2023-02-21.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct serial{
    string num;
    int length;
    int sum=0;
};

bool cmp(const serial &i1, const serial &i2){
    if(i1.num.length() != i2.num.length())
        return i1.length < i2.length;
    if(i1.sum != i2.sum)
        return i1.sum < i2.sum;
    return i1.num < i2.num;
}

int main(){
    int n;
    vector<serial> srl;
    cin >> n;
    srl.assign(n, {});

    for(int i=0; i<n; i++){
        cin >> srl[i].num;
        srl[i].length = srl[i].num.length();
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < srl[i].length; j++) {
            if (srl[i].num.at(j) >= 48 && srl[i].num.at(j) <= 57)
                srl[i].sum += srl[i].num.at(j)-'0';
        }
    }

    sort(srl.begin(), srl.end(), cmp);

    for(int i=0; i<n; i++) {
        cout << srl[i].num << '\n';
    }
}
