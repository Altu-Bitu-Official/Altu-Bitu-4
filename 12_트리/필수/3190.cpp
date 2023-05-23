#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int game(vector<vector<int>>& board, vector<pair<int, char>>& turning, int n) {
    int ans = 0;
    queue<pair<int, int>> snake; // FIFO
    snake.push({ 1,1 }); // 시작위치
    board[1][1] = -1;

    int dx[4] = { 1, 0, -1, 0 };
    int dy[4] = { 0, 1, 0, -1 }; // 우 하 좌 상 (오른쪽으로 90도 증가)
    int direction = 0; // 오른쪽이 디폴트
    int turn_index = 0; // 현재 turning point

    while (true) {
        ans++;

        pair<int, int> head = snake.back();
        head.first += dy[direction];
        head.second += dx[direction];

        if (head.first <= 0 || head.first > n || head.second <= 0 || head.second > n || board[head.first][head.second] == -1) {
            
            break;
        }

        if (board[head.first][head.second] == 0) {
            // 사과가 없음
            pair<int, int> tail = snake.front();
            snake.pop();
            board[tail.first][tail.second] = 0;
        }

        snake.push(head);
        board[head.first][head.second] = -1;

        if (turn_index < turning.size() && turning[turn_index].first == ans) {
            // 방향 전환
            direction = turning[turn_index].second == 'L' ? (direction + 3) % 4 : (direction + 1) % 4;
            turn_index++;
        }
    }

    return ans;
}

int main() {
	// 입력
	int n, k;
	cin >> n >> k;
	vector<vector<int>> board(n + 1, vector<int>(n + 1, 0)); // 1행 1열이 원점인 보드
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        board[x][y] = 1;
        //cout << x << y << endl;
    }

	int L; // 방향정보
	cin >> L;
	vector<pair<int, char>> turning(L);
    int x; char c;
	for (int i = 0; i < L; i++) {
		cin >> x >> c;
		turning[i] = { x, c };
	}
	
	// 출력
	cout << game(board, turning, n);

	return 0;
}