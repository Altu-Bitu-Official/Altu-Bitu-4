
#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int n;
    int k;
    priority_queue<int, vector<int>, greater<int>> matrix; // min heap 
    cin >> n;

    for(int i=0; i<pow(n,2); i++){
        cin >>k;
        if(matrix.size()<n){ //heap의 사이즈가 n이 될때까지 입력받는 수마다 push
            matrix.push(k);
        }
        else if(matrix.top()<k){ //heap의 사이즈가 n 이상이고 heap의 최솟값보다 k가 클 시 push
            matrix.push(k);
            matrix.pop();
        }
    }

    cout << matrix.top();
    return 0;

}