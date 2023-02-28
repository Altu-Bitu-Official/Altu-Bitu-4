#include<iostream>
#include<queue>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	queue<int> arr;

	for (int i = 1; i <= n; i++) {
		arr.push(i);
	}//1~n까지의 원

	while (arr.size() != 1) {
		for (int i = 1; i < k; i++) {
			int tmp = arr.front();
			arr.pop(); 
			arr.push(tmp); //k번째 숫자를 pop
	}
		
	cout << '<';
	for (int i = 0; i < n; i++) {
		cout << arr.front() << ", ";
		arr.pop();
	}
	cout << '>';
}