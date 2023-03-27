#include <iostream>
#include <vector>
#define MAX 2147483647;

using namespace std;

int getTime(int block, int standard, vector<int> &height) {
    int time=0;
    int num;

    for(int i=0; i<height.size(); i++) {
        if(height[i]==0) {
            continue;
        }
        //사용한 블럭 수 계산
        num=height[i]*(i-standard);
        block+=num;

        //기준보다 높이 낮으면 채우고
        if(i<standard) {
            time-=num;
        } else if(i>standard) {
            //기준보다 높이 높으면 제거해야 함
            time+=num*2;
        }
    }

    //블럭 사용 개수 초과하면 불가능
    if(block<0) {
        return MAX;
    }
    return time;
}

int main() {
    int n, m, b, tmp, tmp_time, standard_height;
    cin >> n >> m >> b;

    int time=MAX;

    vector<int> height(257, 0);

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> tmp;
            height[tmp]++;
        }
    }

    //채우는 시간이 더 적으니까 제일 긴 높이 맞추는 것 부터
    for(int i=256; i>=0; i--) {
        tmp_time = getTime(b, i, height);
        if(time>tmp_time) {
            time=tmp_time;
            standard_height=i;
        } else if(time==tmp_time) {
            //소요되는 시간 동일하면 길이만 높은 애로 갱신
            standard_height=max(standard_height, i);
        }
    }

    cout << time << " " << standard_height;

    return 0;
}