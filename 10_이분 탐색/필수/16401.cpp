#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

int getEachCandy(int amount, vector<int> &candy){
    int sum =0;
    for(int i=candy.size()-1 ; i>=0; i--){
        int tmp = candy[i]/amount;
        if(tmp == 0){
            return sum;
        }
        sum += candy[i]/amount;
    }
    return sum;
}

int distributeCandy(int m, int max, int sum, vector<int> &candy){
    int left = 1;
    int right = max;

    while(left <= right){
        int mid = (left+right)/2;
        if(getEachCandy(mid, candy) >= m){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }
    return left - 1;
}

int main(){
    int m, n;
    long long sum = 0;
    cin >> m >> n;
    vector<int> candy(n, 0);

    for(int i=0; i<n; i++) {
        cin >> candy[i];
        sum += candy[i];
    }

    sort(candy.begin(), candy.end());

    int max = (candy.back() < sum/m) ? candy.back() : sum/m;
    cout << distributeCandy(m, max, sum, candy);
}