#include <iostream>
#include <string>

using namespace std;

int getEndnumber(int n) {
	// n번째 종말의 수를 찾는 함수

	int num = 666 - 1;

	while (n > 0) {
		string s = to_string(++num);
		if (s.find("666") != s.npos) {
			n--;
		}
	}
	return num;
}
int main() {
	int n;

	cin >> n;

	cout << getEndnumber(n);

	return 0;

}