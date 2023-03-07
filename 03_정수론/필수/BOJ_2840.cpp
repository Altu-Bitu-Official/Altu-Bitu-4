#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n, k, s, arrow = 0;
	char letter;
	bool is_wheel = true;

	//입력
	cin >> n >> k;
	vector<char> wheel(n,'?'); //n칸인 바퀴 생성
	for (int i = 0; i < k; i++) {
		cin >> s >> letter;
		arrow = (arrow + s) % n;
		if (wheel[arrow] == '?' || wheel[arrow] == letter) {
			wheel[arrow] = letter;
		}
		else { //다른 글자가 들어가있으면
			is_wheel = false; //해당하는 바퀴가 존재하지 않음
			break;
		}
	}
	//중복값 확인
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (wheel[i] == wheel[j] && wheel[i] != '?') {
				is_wheel = false;
			}
		}
	}

	//출력
	arrow += n;
	if (!is_wheel) {
		cout << '!';
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << wheel[(arrow - i) % n];
		}
	}
	return 0;
}