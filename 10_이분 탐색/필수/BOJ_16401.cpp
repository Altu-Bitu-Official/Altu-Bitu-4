#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//목표 길이와 과자의 길이가 담긴 배열을 받고, 목표 길이일 때 몇 명에게 과자를 나눠줄 수 있는지를 리턴하는 함수
int cntPeople (int l, vector<int>& len) {
    int cnt = 0;

    for (int i : len) {
        if (i >= l) {
            cnt += i / l;
        }
    }
    return cnt;
}

//이진 탐색을 통해 모두에게 과자를 나눠줄 수 있는 길이의 최댓값을 구하는 함수
int binarySearch (int left, int right, int target, vector<int>& len) {
    int mid, ppl;

    while (left <= right) {
        mid = (left + right) / 2;
        ppl = cntPeople(mid, len);

        if (ppl >= target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left - 1;
}

int main() {
    int m, n;
    vector<int> len;
    
    //입력
    cin >> m >> n;
    len.assign(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> len[i];
    }
    sort(len.begin(), len.end());

    //출력
    cout << binarySearch(1, len[n-1], m, len);
}