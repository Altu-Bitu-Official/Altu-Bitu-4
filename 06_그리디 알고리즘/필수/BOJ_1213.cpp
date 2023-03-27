#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
bool isPossible(string s) {
	vector<int> alphabet(26, 0);
	for (int i = 0; i < s.size(); i++) {
		alphabet[s[i] - 'A']++;
	}
	vector<int> chosen;
	for (int i = 0; i < alphabet.size(); i++) {
		if (alphabet[i] != 0) {//해당 알파벳이 한개라도 존재하면
			chosen.push_back(alphabet[i]);
		}
	}
	int odd_count=0;
	for (int i = 0; i < chosen.size(); i++) {
		if (chosen[i] % 2 != 0) {//해당 알파벳의 개수가 홀수이면
			odd_count++;//카운트
		}
	}

	if (odd_count > 1) {//개수가 홀수인 알파벳이 두개 이상이면 팰린드롬을 만들 수 없다
		return false;
	}
	else return true;
}

int main() {
	string s;
	string answer = "";
	cin >> s;

	if (!isPossible(s)) {
		cout << "I'm Sorry Hansoo\n";
		return 0;
	}

	vector<int> alpha(26, 0);
	for (int i = 0; i < s.size(); i++) {
		alpha[s[i] - 'A']++;
	}

	int odd_count = 0;
	char odd_alpha;
	int oddnum_count=0;
	int oddnum_index;
	for (int i = 0; i < alpha.size(); i++) {
		if (alpha[i] % 2 != 0) {//해당 알파벳의 개수가 홀수이면
			odd_count++;//카운트
			odd_alpha = 'A' + i;
			oddnum_count = alpha[i];//홀수 알파벳의 개수 저장
			oddnum_index = i;
			break;
		}
	}
	if (odd_count == 1) {//홀수개수인 알파벳이 존재하는경우
		stack<char> st1;

		if (oddnum_count != 1) {//홀수개수인 알파벳의 개수가 3 이상일 경우
			alpha[oddnum_index]--;
		}
		for (int j = 0; j < 26; j++) {
			int temp = alpha[j];//해당 알파벳의 개수 저장
			if (temp != 0 && temp % 2 == 0) {//알파벳개수가짝수면
				for (int k = 0; k < temp / 2; k++) {//그 개수의 반만큼
					st1.push('A' + j);//스택에저장하고..
					alpha[j]--;//알파벳개수 하나감소
					answer += 'A' + j;
				}
			}
		}
		
		answer += odd_alpha;//홀수개수인 알파벳 하나를 중간에 붙이기
		

		while (!st1.empty()) {
			answer += st1.top();
			st1.pop();
		}

	}
	else {//전부 짝수인 경우
		stack<char> st2;
		
			for (int j = 0; j < 26; j++) {
				int temp = alpha[j];
				if (temp != 0) {//해당 알파벳의 개수가 영이 아니면
					for (int k = 0; k < temp / 2; k++) {
						st2.push('A' + j);
						alpha[j]--;
						answer += 'A' + j;
					}
					
				}
			
			}
			

			while (!st2.empty()) {
				answer += st2.top();
				st2.pop();
			}

	}

	cout << answer << "\n";

}