#include <iostream>
#include <string>

using namespace std;

int getSum(int* arr) {
	int sum = 0;
	for (int i = 0; i < 30; i++) {
		sum += arr[i];
	}
	return sum;
}

int setArr(string a, int* arr) {

	for (int i = 0; i < a.size(); i++) {
		int tmp = a[i] - 65;
		arr[tmp]++;
	}
	return arr[30];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp, count = 0;
	cin >> n;
	string first, input;
	cin >> first;

	n = n - 1;
	while (n--) {
		int arr[30] = { 0 };
		setArr(first, arr);
		cin >> input;
		if (input.size() == first.size()) {
			for (int i = 0; i < input.size(); i++) {
				tmp = input[i] - 65;
				if (arr[tmp] != 0) {
					arr[tmp]--;
				}
			}
			if (getSum(arr) <= 1) {
				count++;
				continue;
			}
		}
		else if (input.size() - first.size() == 1) {
			for (int i = 0; i < input.size(); i++) {
				tmp = input[i] - 65;
				if (arr[tmp] != 0) {
					arr[tmp]--;
				}
			}
			if (getSum(arr) == 0) {
				count++;
				continue;
			}
		}
		else if (first.size() - input.size() == 1) {
			for (int i = 0; i < input.size(); i++) {
				tmp = input[i] - 65;
				if (arr[tmp] != 0) {
					arr[tmp]--;
				}
			}
			if (getSum(arr) == 1) {
				count++;
				continue;
			}
		}
		else {
			continue;
		}
	}
	cout << count;
}