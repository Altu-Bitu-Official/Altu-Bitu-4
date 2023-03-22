#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
<구현, 문자열>
1) 같은 단어
2) 두 단어에서 다른 문자의 개수가 1개
3) 두 단어에서 다른 문자의 개수가 2개 but 길이 같음
*/

void countFreq(string word, vector<int>& freq) {
	//입력받은 word에서 각 알파벳의 개수 세기
	for (int i = 0; i < word.length(); i++) {
		//word의 길이만큼 반복
		freq[word[i] - 'A']++; //'A' - 'A' -> 0번 인덱스
	}
}
int countDiff(string word, vector<int> fw_freq) {
	vector<int> freq(26, 0); //새로 입력받은 word의 알파벳 개수 저장
							 //26개 알파벳, 0으로 초기화

	int diff = 0; //fw와의 차이 저장할 변수
	countFreq(word, freq); //새로 입력받은 word의 알파벳 수

	for (int i = 0; i < 26; i++) {
		diff += abs(fw_freq[i] - freq[i]); //fw와 word의 빈도수 차이 저장
		                              //abs(절댓값) 사용 - #include <cmath>

	}

	return diff;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	int ans = 0; 
	string fw; //첫번째 단어
	cin >> n;
	cin >> fw;

	vector<int> fw_freq(26, 0); //정수형 벡터
	           //각 알파벳의 개수 저장, 26개 알파벳, 0으로 초기화
	countFreq(fw, fw_freq); //fw의 각 알파벳에 대한 개수 count

	for (int i = 1; i < n; i++) {
		//int i=0일 때가 fw이므로 i=1부터
		string word;
		cin >> word;

		int diff = countDiff(word, fw_freq); //빈도수 차이 diff

		if (diff == 0 || diff == 1 || (diff == 2 && fw.length() == word.length()))
		{ // 1,2,3번의 조건중에 하나라도 만족할 경우
			ans++;
		}
	}

	cout << ans;
	return 0;
}