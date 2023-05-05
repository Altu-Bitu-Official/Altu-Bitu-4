#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, k;
int ans = 1;
int start_idx, end_idx; //로봇을 올리고 내리는 위치
vector<int> a;
vector<bool> is_robot;

//1단계: 회전
void rotate() {
	start_idx--;
	if (start_idx == 0) {
		start_idx = 2 * n;
	}
	end_idx--;
	if (end_idx == 0) {
		end_idx = 2 * n;
	}

	//내리는 위치에 로봇이 있으면 로봇 내려줌
	if (is_robot[end_idx]) {
		is_robot[end_idx] = false;
	}
}

//2단계: 이동
void move() {
	queue<int> move_q;
	for (int i = end_idx; i > 0; i--) {
		move_q.push(i);
	}
	for (int i = 2 * n; i > end_idx; i--) {
		move_q.push(i);
	}

	for (int i = 0; i < n; i++) {
		int next_idx = move_q.front();
		move_q.pop();
		int prev_idx = move_q.front();

		//현재 위치에 로봇이 없고 이전 위치에 로봇이 있으며 내구도가 0보다 큰 경우 로봇 옮김
		if (!is_robot[next_idx] && is_robot[prev_idx] && a[next_idx] > 0) {
			is_robot[next_idx] = true;
			is_robot[prev_idx] = false;
			a[next_idx]--;
		}
	}

	//내리는 위치에 로봇이 있으면 로봇 내려줌
	if (is_robot[end_idx]) {
		is_robot[end_idx] = false;
	}
}

//3단계: 로봇 올림
void put_robot() {
	if (a[start_idx] > 0) {
		is_robot[start_idx] = true;
		a[start_idx]--;
	}
}

//4단계: 종료 조건 확인
bool end_check() {
	int cnt = 0;
	for (int i = 1; i <= 2 * n; i++) {
		if (a[i] == 0) {
			cnt++;
		}
	}
	if (cnt >= k) {
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	cin >> n >> k;

	a.assign(2 * n + 1, 0);
	for (int i = 1; i <= 2 * n; i++) {
		cin >> a[i];
	}
	start_idx = 1;
	end_idx = n;
	is_robot.assign(2 * n + 1, false);

	//연산
	while (true) {
		rotate();
		move();
		put_robot();
		if (end_check()) {
			break;
		}
		ans++;
	}

	//출력
	cout << ans;

	return 0;
}