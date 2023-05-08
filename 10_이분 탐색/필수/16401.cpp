#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	vector<int> arr;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		arr.push_back(a);
	}
	
	sort(arr.begin(), arr.end());

	int left = 1, right = *max_element(arr.begin(), arr.end());

	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2; 
		int target = 0;
		
		for (int i = 0; i < m; i++) {
			target += arr[i] / mid;
		}
		if (target >= n) { 
			left = mid + 1;
			ans = mid;
		}
		else if (target < n) { 
			right = mid - 1;
		}
	}
	cout << ans << "\n";

	return 0;
}