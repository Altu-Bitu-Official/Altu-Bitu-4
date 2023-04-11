#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
/*
 * 회의가 끝나는 시각이 빠른 회의부터 배정하면 되므로 그리디 알고리즘을 이용한다.
 * 이 때, 마지막으로 진행한 회의가 끝난 시각보다 빠른 시각에 시작하는 회의는 배정이 불가능한 점을 고려해야 한다.
 */

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	// 입력
	int n;
	cin >> n;
	vector<pair<int, int>>v;
	for (int i = 0; i < n; i++) {
		int start, end;
		cin >> start >> end;
		v.push_back({ end,start }); //회의가 끝나는 시각을 기준으로 정렬할 것이므로 편의상 end부터 입력
	}
	// 연산
	sort(v.begin(), v.end()); //끝나는 시각 기준 오름차순 정렬

	int finish_conference = 0, answer = 0;
	for (int i = 0; i < v.size(); i++) {//회의 끝나는 시각이 빠른 순서대로 배정
		if (v[i].second < finish_conference) { //회의 시작하는 시각이 기존 종료 시각보다 빠르다면 회의실 배정 불가 
			continue;
		}
		finish_conference = v[i].first; //회의 종료 시각 갱신
		answer++; //배정 가능 회의 수 갱신
	}
	// 출력
	cout << answer;
    
    return 0;
}