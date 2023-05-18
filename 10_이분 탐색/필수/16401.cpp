#include <iostream>
#include <vector>

using namespace std;

int getMaxLength(int m, int n, vector<int> &lengths, long max) {
    //과자 최소길이
    long left=1;
    //과자 최대길이
    long right=max;
    int flag=false;

    while(left<=right) {
        int cnt=0;
        long mid=(left+right)/2;

        for(int i=0; i<n; i++) {
            //과자 하나 몇 명한테 나눠줄 수 있는지
            cnt+=lengths[i]/mid;
        }

        if(cnt>=m) {
            //개수 맞으면 flag 참 처리
            flag=true;
            left=mid+1;
        } else if(cnt<m) {
            right=mid-1;
        }
    }

    if(flag) {
        return right;
    }
    return 0;
}

int main() {
    int m, n;
    long total=0;

    cin >> m >> n;

    vector<int> lengths(n);
    for(int i=0; i<n; i++) {
        cin >> lengths[i];
        total+=lengths[i];
    }

    long max = total/m;
    cout << getMaxLength(m, n, lengths, max);

    return 0;
}