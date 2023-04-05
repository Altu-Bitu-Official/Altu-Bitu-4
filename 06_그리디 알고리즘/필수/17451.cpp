#include <iostream>
#include <vector>

using namespace std;

void findMinVelocity(long long &v, int &next) {
    if (v >= next && v % next == 0) { // 속도가 이미 배수로 설정되어 있다면 리턴
        return;
    }
    // 속도를 v보다 큰 next의 가장 작은 배수로 설정
    v = next * (v / next + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;       // 행성 수
    long long v = 0; // 속도
    
    cin >> n;
    vector<int> planets(n, 0);

    for(int i = 0; i < n; i++) {
        cin >> planets[i];
    }

    for(int i = n-1; i >= 0; i--) { // 뒤에서부터 시작
        findMinVelocity(v, planets[i]);
    }

    cout << v;

    return 0;
}