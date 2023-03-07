//
// Created by LG on 2023-02-28.
//
#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    deque<int> numbers;

    for(int i=0; i<n; i++)
        numbers.push_back(i+1);

    cout << "<";
    int cnt = 1;
    while(!numbers.empty()){
        if(cnt%k == 0) {
            int a = numbers.front();
            numbers.pop_front();
            if(cnt == k)
                cout << a;
            else
                cout << ", " << a;
        }
        else{
            int a = numbers.front();
            numbers.pop_front();
            numbers.push_back(a);
        }
        cnt++;
    }
    cout << ">";

}

