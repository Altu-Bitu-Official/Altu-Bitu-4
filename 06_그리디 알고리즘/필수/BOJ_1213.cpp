#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 팰린드롬: 앞에서부터 읽든지, 뒤에서부터 읽든지 동일한 문자열

/* 홀수개인 알파벳이 1개 이하여야만 만들 수 있음
* 0개인 경우: 모두 짝수개이므로 앞부분을 사전 순으로 정렬한 후 출력 -> 뒷 부분은 뒤집어서 출력
* 1개인 경우: 홀수개인 알파벳 하나 빼서 중앙에 배치 -> 모두 짝수개 됐으므로 위와 동일하게 적용
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	string name;
	cin >> name; 

	int num = 0; // 홀수 개인 알파벳 개수
	int k;
	vector <int> alphabet(26, 0); // 알파벳 26개 모두 0으로 초기화

	for (int i = 0; i < name.size(); i++) { alphabet[name[i] - 65] += 1; }
	for (int i = 0; i < alphabet.size(); i++) { 
		if (alphabet[i] % 2 != 0) {
			num = num + 1; // 홀수개인 문자의 개수
			if (num == 1) k = i; // 홀수개인 문자가 무엇인지 
		}
	}
	string s; // 문자열의 앞부분 저장

	// 홀수개인 알파벳은 1개 이하여야 함
	if (num > 1) cout << "I'm Sorry Hansoo";
	
	else {
		// 홀수개인 알파벳이 있는 경우 (문자열 길이 홀수)
		if (num == 1) {
			char center = char(k + 65);
			alphabet[k]--;
			for (int i = 0; i < alphabet.size(); i++) { alphabet[i] /= 2; }
			for (int i = 0; i < alphabet.size(); i++) {
				while (alphabet[i] > 0) {
					s.push_back(char(i + 65));
					alphabet[i]--;
				}
			}
			cout << s << center;
			reverse(s.begin(), s.end());
			cout << s;
		}

		// 홀수개인 알파벳이 없는 경우 (문자열 길이 짝수) 
		if (num==0) {
			for (int i = 0; i < alphabet.size(); i++) { alphabet[i] /= 2 ; }

			for (int i = 0; i < alphabet.size(); i++) {
				while (alphabet[i] > 0) {
					s.push_back(char(i+65));
					alphabet[i]--;
				}
			}
			cout << s;
			reverse(s.begin(), s.end());
			cout << s;
		}
	}
	
	return 0;
}