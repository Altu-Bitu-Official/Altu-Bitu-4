#include <iostream>
#include <queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n,k;
	cin >> n >> k;
	
	queue<int> que;
	for (int i = 0; i < n; i++){
        que.push(i);
    }

	cout << "<";

	while (que.size() > 1) {
		for (int i = 1; i < k; i++) {
			int a = que.front();
			que.pop(); 
			que.push(a); 
		}
		cout << que.front() << ", ";
		que.pop();
	}
	cout << que.front() << ">";
}