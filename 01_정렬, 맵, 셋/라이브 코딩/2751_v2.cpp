#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 입력
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	// 연산
	sort(arr.begin(), arr.end());
	// 출력
	for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}
	return 0;
}