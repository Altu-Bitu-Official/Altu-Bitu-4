#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string name;
	cin >> name; //이름 입력력
	int arr[26] = { 0 }; //배열 선언(알파벳 개수)
	int odd = 0;
	int size = name.size();
	string palindrome = "";
	string tmp = "";
	char odd_c;
	for (int i = 0; i < name.size(); i++) {
		arr[name[i] - 'A']++;
	} //알파벳 개수 저장
	//홀수 존재 여부 확인인
	for (int i = 0; i < 26; i++) {
		if (arr[i] % 2 != 0) {
			odd++;
			odd_c = char(i + 'A');
		}
	}
	//
	if (odd >= 2) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < arr[i] / 2; j++) {
			palindrome += (i + 'A');
		}
	}
	if (odd == 1) {
		palindrome += odd_c;
	}
	for (int i = 25; i >= 0; i--) {
		for (int j = 0; j < arr[i] / 2; j++) {
			palindrome += (i + 'A');
		}
	}


	cout << palindrome;
}