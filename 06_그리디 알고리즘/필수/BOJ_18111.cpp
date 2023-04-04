#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;

//시간이 짧은 순, 땅의 높이가 높은 순으로 정렬
bool cmp(ii t1, ii t2) {
	if (t1.first != t2.first) {
		return t1.first < t2.first;
	}
	return t1.second > t2.second;
}

//걸리는 시간을 계산하는 함수
int getTime(vector<int>& ground, int b, int height) {
	int remove_block = 0; //평평하게 만들기 위해 제거해야하는 블럭의 개수
	int add_block = 0; //평평하게 만들기 위해 추가해야하는 블럭의 개수

	vector<int> new_ground = ground;
	for (int i = 0; i < ground.size(); i++) {
		//현재 칸의 블럭의 개수가 기준 높이보다 낮다면 인벤토리에서 블럭을 빼서 채우기
		if (new_ground[i] < height) {
			add_block += (height - new_ground[i]); //부족한 블럭만큼 채우기
			b -= (height - new_ground[i]);
			//인벤토리에 있는 블럭이 부족해지면 불가능하므로 -1 출력
			if (b < 0) {
				return -1;
			}
		}
		//현재 칸의 블럭의 개수가 기준 높이보다 높다면 제거해서 인벤토리에 넣기
		else {
			remove_block += (new_ground[i] - height);
			b += (new_ground[i] - height);
		}
	}
	return 2 * remove_block + add_block; //시간
}

ii solution(vector<int>& ground, int b) {
	vector<ii> result; //(걸리는 시간, 땅의 높이)
	
	//중간에 인벤토리가 부족해질 경우를 대비하여 가장 높은 블럭부터 처리
	sort(ground.rbegin(), ground.rend());

	//땅의 최저높이와 최대높이 구함
	int min_block = ground[ground.size() - 1];
	int max_block = ground[0];

	//높이를 하나씩 높여가면서 시간 계산
	for (int i = min_block; i <= max_block; i++) {
		int time = getTime(ground, b, i);
		//-1이 아닌 경우만 인벤토리에 블럭이 충분하므로 추가
		if (time != -1) {
			result.push_back({ time, i });
		}
		//-1인 경우 블럭이 앞으로도 계속 부족할 예정이므로 반복문 종료
		else {
			break;
		}
	}

	//시간이 짧은 순, 땅의 높이가 높은 순으로 정렬
	sort(result.begin(), result.end(), cmp);
	return result[0];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n, m, b;
	cin >> n >> m >> b;

	vector<int> ground(n * m);
	for (int i = 0; i < n * m; i++) {
		cin >> ground[i];
	}

	//연산
	ii result = solution(ground, b);

	//출력
	cout << result.first << " " << result.second;

	return 0;
}