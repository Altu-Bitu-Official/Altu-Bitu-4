#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, int> ii;

//같은 문자를 정확히 K개 포함하는 가장 짧은 연속 문자열의 길이 반환
//같은 문자를 정확히 K개 포함하고 문자열의 첫 번째와 마지막 글자가 같은 가장 긴 연속 문자열의 길이 반환
ii getLength(string w, int k) {
	if (k == 1) {
		return { 1,1 };
	}

	int n = w.length(); //문자열의 길이
	vector<vector<int>> position(26, vector<int>()); //position[i]: 알파벳 i의 위치 배열
	for (int i = 0; i < n; i++) {
		position[w[i] - 'a'].push_back(i);
	}

	int length = 0; //연속 부분 문자열의 길이
	int min_length = 1e4 + 1; //최단 연속 부분 문자열의 길이
	int max_length = 0; //최장 연속 부분 문자열의 길이

	for (int i = 0; i < 26; i++) {
		//해당 알파벳의 개수가 k개 이상인 경우에만 탐색
		if (position[i].size() >= k) {
			int left = 0, right = k - 1; //w[left]부터 w[right]까지 알파벳 i가 k개 존재하도록 함

			int length = position[i][right] - position[i][left] + 1;
			min_length = min(min_length, length);
			max_length = max(max_length, length);

			//left, right를 증가시키며 k 간격으로 다 탐색
			while (right < position[i].size() - 1) {
				left++;
				right++;

				length = position[i][right] - position[i][left] + 1;
				min_length = min(min_length, length);
				max_length = max(max_length, length);
			}
		}
	}

	//만족하는 연속 문자열이 없으므로 -1 반환
	if (max_length == 0) {
		return { -1,-1 };
	}
	return { min_length, max_length };
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int t, k;
	string w;
	cin >> t;

	while (t--) {
		cin >> w >> k;

		//연산
		ii result = getLength(w, k);

		//출력
		if (result.first == -1) {
			cout << "-1\n";
		}
		else {
			cout << result.first << " " << result.second << "\n";
		}
	}

	return 0;
}