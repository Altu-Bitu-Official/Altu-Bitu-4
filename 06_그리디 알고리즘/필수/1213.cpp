#include<iostream>
#include <vector>
#include <cmath>
#include<algorithm>//reverse
using namespace std;
bool isPalindrome(string input) {
	//알파벳 세기
	vector<int> alphabet(26, 0);
	for (int i = 0; i < input.size(); i++) {
		//각 문자 갯수 세기
		int alphabet_num = input[i] - 'A';
		alphabet[alphabet_num]++;
	}

	//이제 갯수차이를 봄
	int count;
	for (int i = 0; i < alphabet.size(); i++) {
		if (alphabet[i] > 0) {//뭐 들어있으면
			count = alphabet[i];
			break;
		}
	}
	//이제 갯수 다른지를 본다.
	int one_dif_count=0;
	for (int i = 0; i < alphabet.size(); i++) {
		if (count != alphabet[i]) {//갯수가 다를경우? 
			//다르면 딱 1개차이만 허용&딱 1개차이인게 하나만 있어야 함
			if (abs(count - alphabet[i]) == 1) {//딱 1개 차이
				one_dif_count++;
			}
		}
	}
	//이제1개차이인게 딱 하나만 있는지를 확인
	if (one_dif_count > 1)
	{
		return false;
	}
	else {
		return true;
	}


}

void makePalindrome(string input, string& answer) {
	//알파벳 세기
	vector<int> alphabet(26, 0);
	vector<int> alpha_original(26, 0);
	for (int i = 0; i < input.size(); i++) {
		//각 문자 갯수 세기
		int alphabet_num = input[i] - 'A';
		alphabet[alphabet_num]++;
	}
	//백업
	alpha_original = alphabet;
	//알파벳 갯수 조작(/2로)
	for (int i = 0; i < alphabet.size(); i++) {
		alphabet[i] /= 2;//2로 나눈 몫
	}
	//2인게 있고, 나머지는 다 1인경우-> 이럴경우 2인거를 연속으로 채우기 위해
	bool special_case = false;
	int count = 0;
	for (int i = 0; i < alphabet.size(); i++) {
		if (alphabet[i] == 2) {
			count = 2;
		}
		if (count==2 && count != alphabet[i]) {//다르다면 그건 1이어야함.
			if (alphabet[i] != 1 && alphabet[i] !=0)
			{
				special_case = false;
				break;
			}
			else {
				special_case = true;
			}
		}
	}

	string half = "";
	while (half.size() != input.size() / 2) {//반만큼 채워질 때까지 반복
		bool flag = false;
		for (int i = 0; i < 26; i++) {
			if (alphabet[i] > 0) {//뭐 들어있으면
				half += i + 'A';
				if (special_case&&!flag) {//스페셜케이스면 한번만 수행
					half += i + 'A';//또 더함(연속적으로)
					flag = true;
				}
				alpha_original[i]-=(2*alphabet[i]);
			}
		}
	}

	//홀수면? 홀수개인거를  answer 의 맨 뒤로 보내기
	answer += half;
	for (int i = 0; i < 26; i++) {
		if (alpha_original[i] == 1) {
			answer += i + 'A';
			break;
		}
	}
	//반쪽짜리 뒤집어서 answer에 더하고 마무리
	reverse(half.begin(), half.end());
	answer += half;
}

int main() {
	//문자열 입력받기
	string input;
	cin >> input;

	//판별하기
	//1. 문자열 전체를 반으로 쪼갠다. 
	//2. 반으로 쪼갠거에서 각 문자 갯수 세기
	//3. 1) 홀수: 혼자 다른 문자가 하나만 있어야 함.   
	//3. 2) 짝수: 각 문자 갯수가 같아야 함
	if (!isPalindrome(input)) {
		cout << "I'm Sorry Hansoo";
	}
	else {
		string answer = "";
		makePalindrome(input, answer);
		cout << answer;
	}

	return 0;
}