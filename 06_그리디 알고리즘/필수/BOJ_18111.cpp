#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//b와 높이 배열, 목표 높이, b를 받아 블럭을 이동하고, 그 후 소요된 시간과 b를 계산하는 함수
int moveBlocks(vector<int> height, int desired_h, int b) {
    int time = 0;
    for (int n : height) {
        if (n < desired_h) {    //목표 높이보다 낮을 때
            time += desired_h-n;
            b -= desired_h-n;
        }
        else {  //목표 높이보다 높을 때
            time += 2 * (n-desired_h);
            b += n-desired_h;
        }
    }
    if (b < 0) {    //b가 음수 -> 케이스 성립 x
        return -1;
    }
    else {
        return time;
    }
}

//높이 배열과 b를 받고, 블럭을 이동할 수 있는 모든 경우를 시도한 후 최소 시간과 그 때 높이를 구하는 함수
void calcMinimumTime(vector<int>& height, int b) {
    int max_h = height[0], min_h = height[height.size()-1], min_t = 500*500*2*256, answer_h;

    if (height.size() == 1) {      //배열의 크기가 1일 때
        cout << 0 << ' ' << height[0];
        return;
    }

    for (int i = max_h; i >= min_h; i--) {
        int n = moveBlocks(height, i, b);   //블럭 이동
        if (n >= 0) {   //-1 : 성립 x.
            if (min_t > n) {    //시간이 최소일 경우
                min_t = n;
                answer_h = i;
            }
        }
    }
    cout << min_t << ' ' << answer_h;
    return;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, b, max_h, min_h;
    vector<int> height;
    
    //입력 
    cin >> n >> m >> b;
    height.assign(n*m, 0);

    for (int i = 0; i < n*m; i++) {
        cin >> height[i];
    }
    sort(height.begin(), height.end(), greater<int>()); //내림차순으로 높이 정렬
    
    //출력
    calcMinimumTime(height, b);
}