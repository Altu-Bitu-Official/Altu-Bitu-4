#include <iostream>;
#include <string>;

using namespace std;



int main() {

	int arr[26] = { 0 };

	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		int index = str[i] - 65;
		arr[index]++;
	}


	int odd = 0;
	int odd_index;
	string sol = "";
	bool flag = false;

	// 홀수 갯수 세기
	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2 != 0)
			odd++;
	}

	// 홀수가 1개 이상이면 실패
	if (odd > 1) {
		cout << "I'm Sorry Hansoo";
	}

	else {
		for (int i = 0; i < 26; i++) {
			if (arr[i] % 2 != 0) {
				odd_index == i;
				flag = true;
			}

		}

		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < arr[i] / 2; j++) {
				sol += i + 'A';
			}
		}

		for (int i = 0; i < 26; i++)
			if (arr[i] % 2)
				sol += i + 'A';


		for (int i = 25; i >= 0; i--) {
			for (int j = 0; j < arr[i] / 2; j++) {
				sol += i + 'A';
			}
		}
	}

	cout << sol;
	return 0;
}