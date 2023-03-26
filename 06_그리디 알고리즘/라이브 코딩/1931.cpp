// 회의실 배정 - 회의가 빨리 끝나는 순으로 자리 배정

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, cnt = 0; // 회의 수, 최대 사용가능 회의 개수
    int start, end;
    vector<pair<int,int>> meeting;
    // 입력
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> start >> end;
        meeting.push_back({end, start});
    }
    sort(meeting.begin(), meeting.end()); // 회의가 끝나는 순으로 정렬
    
    int t = 0; // 현재 사용중인 회의가 끝나는 시간
    for (int i=0; i<n; i++){
        if (meeting[i].second >= t){ // 회의 시작 시간이 현재 시간 뒤이면
            cnt += 1;
            t = meeting[i].first; // 끝나는 시간 갱신
        }
    }
    cout << cnt;
}