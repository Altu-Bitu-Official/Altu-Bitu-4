#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string a, b;
    int sum;
    int a_array[10001], b_array[10001];
    deque<int> dq;

    cin >> a >> b;

    if(a.size() < b.size()){
        swap(a,b);
    }

    for(int i=0; i<a.size(); i++){
        a_array[i+1] = a[i] - '0';
    }

	for(int i=0; i<b.size(); i++){
		b_array[i + 1 + (a.size()-b.size())] = b[i] - '0';
    }

    for( int i = a.size(); i>0; i--){
        sum = a[i]+b[i];
        if (sum>=10){
            a[i-1]++;
            sum-=10;
        }
        dq.push_back(sum);
    }    

    for(int i =0; i< dq.size(); i++){
        cout << dq[i];
    }
    return 0;
}
