#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int compare(string a, string b) {

	int lengthA = a.size();
	int lengthB = b.size();
	int sumA = 0;
	int sumB = 0;
	int i = 1;

	if (lengthA != lengthB) {
		return lengthA < lengthB;
	}

	if (lengthA = lengthB) {
		for (; i < a.size(); i++) {

			if (a[i] >= '0' && a[i] <= '9') {
				sumA = sumA + a[i];
			}

			if (b[i] >= '0' && b[i] <= '9') {
				sumB = sumB + b[i];
			}
		}

		if (sumA != sumB) {
			return sumA < sumB;
		}
	}

	return a < b;
}

int main(void) {

	ios_base::sync_with_stdio();
	int n;
	int j = 0;
	string N[49];

	cin >> n;

	for (; j < n; j++) {
		cin >> N[j];
	}


	sort(N, N + n, compare);
	for (; j < n; j++) {
		cout << N[j] << std::endl;
	}

	return 0;
}