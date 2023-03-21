#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 비슷한 단어인지 검사하는 함수
int isSimilar(vector<char> s, vector<char> c) {
	int size_s = s.size();
	int size_c = c.size();

	sort(s.begin(), s.end());
	sort(c.begin(), c.end());

	if (s == c) {	// 구성이 같은 단어
		return 1;
	}

	else {
		int cnt = 0;
		
		for (int i = 0; i < size_c; i++) {
			if (find(s.begin(), s.end(), c[i]) == s.end()) {	// 일치하는 알파벳이 없다면 cnt 증가
				cnt++;				
			}			
			else {
				s.erase(find(s.begin(), s.end(), c[i]));	// 일치하는 알파벳이 있다면 지우기
			}
						
		}

		switch (size_s - size_c)
		{
		case 1:	// 첫 번째 단어가 더 길 때
			if (cnt == 0) {	// 모든 알파벳이 첫 번째 단어 안에 존재하면 비슷한 단어
				return 1;
			}
			return 0;	// 첫 번째 단어에 포함되지 않는 알파벳이 존재한다면 비슷한 단어 X

		case 0: case -1:	// 두 단어의 길이가 같거나 첫 번째 단어가 더 짧을 때
			if (cnt == 1) {	// 첫 번째 단어에 포함되지 않는 알파벳이 한 개 있다면 비슷한 단어
				return 1;
			}
			return 0;	// 첫 번째 단어에 포함되지 않는 알파벳이 두 개 이상이면 비슷한 단어 X

		default:	// 두 단어의 길이 차가 1보다 크면 비슷한 단어 X
			return 0;
		}
	}
	
}


int main() {
	int n, cnt = 0;
	string s_word, c_word;
	vector<char> std_word, comp_word;

	// 입력
	cin >> n >> s_word;
	for (int i = 0; i < s_word.size(); i++) {
		std_word.push_back(s_word[i]);
	}
	n--;

	// 연산
	while (n--) {
		cin >> c_word;
		for (int i = 0; i < c_word.size(); i++) {
			comp_word.push_back(c_word[i]);
		}
		cnt += isSimilar(std_word, comp_word);
		comp_word.clear();
	}

	// 출력
	cout << cnt << '\n';

	return 0;
}

