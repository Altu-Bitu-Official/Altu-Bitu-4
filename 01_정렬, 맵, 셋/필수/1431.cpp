#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//길이가 같을 경우 숫자 합을 구하는 함수
int sumNumber(const string& a) {
	int sum = 0;
	for (int i = 0; i < a.length(); i++) {
		if (isdigit(a[i])) {
			sum += (a[i] - '0');
		}
	}
	return sum;
}

// 비교하여 정렬하는 함수 
bool cmp(const string& a, const string& b) {
	if (a.length() != b.length()) {
		return a.length() < b.length();
	}

	if (sumNumber(a) != sumNumber(b)) {
		return sumNumber(a) < sumNumber(b);
	}

	return a < b;

}

int main()
{
	int n;

	//입력
	cin >> n;

	vector<string> arr(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	//연산

	sort(arr.begin(), arr.end(), cmp);

	//출력

	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}

	return 0;
}