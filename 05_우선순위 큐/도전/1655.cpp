#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, num;
	int left = 0, right = 0;
	priority_queue<int, vector<int>, less<int>>pq_left; //왼쪽을 담당하는 max heap
	priority_queue<int, vector<int>, greater<int>>pq_right; //오른쪽을 담당하는 min heap

	//입력
	cin >> n;

	while (n--) {
		cin >> num;
		if (left - right == 0) { // 차이가 0이면 왼쪽에
			pq_left.push(num);
			left++;
		}
		else { //차이가 1이면 오른쪽에 push해서 균형을 맞춤
			pq_right.push(num);
			right++;
		}

		if (!pq_left.empty() && !pq_right.empty()) { // 만약 왼쪽의 최대가 오른쪽의 최소보다 클 경우 swap
			if (pq_left.top() > pq_right.top()) {
				int tmp = pq_left.top();
				pq_left.pop();
				pq_left.push(pq_right.top());
				pq_right.pop();
				pq_right.push(tmp);
			}
		}

		//균형이 왼쪽을 기준으로 맞추어져 있으므로 왼쪽 최대를 출력 
		cout << pq_left.top() << "\n";
	}

	return 0;
}