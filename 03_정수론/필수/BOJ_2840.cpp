#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<char> makeWheel(int n, vector<pair<int, char>>& p) {
	vector<char> wheel(n, '?');
	int index = 0; //현재 화살표가 가리키는 인덱스
	set<int> check; //같은 글자가 두 번 이상 등장하지 않는지 확인하기 위한 집합

	for (int i = 0; i < p.size(); i++) {
		index = (index + p[i].first) % n; //회전한 후 화살표가 가리키는 인덱스
		//아직 바퀴가 비었다면 넣기
		if (wheel[index] == '?') {
			//같은 글자가 두 번 이상 등장하면 안됨
			if (check.count(p[i].second) != 0) {
				wheel[0] = '!';
				return wheel;
			}
			wheel[index] = p[i].second;
			check.insert(p[i].second);
			continue;
		}

		//이전에 채워진 값이랑 같다면 넘어가기
		if (wheel[index] == p[i].second) {
			continue;
		}
		else { //다르다면 종이에 해당하는 행운의 바퀴가 없으므로 반복문 종료
			wheel[0] = '!';
			return wheel;
		}
	}

	//마지막 회전의 화살표가 가리키는 문자부터 담을 벡터 result
	vector<char> result(n); 
	for (int i = 0; i < n; i++) {
		if (index - i < 0) {
			index += n;
		}
		result[i] = wheel[index - i];
	}

	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k, s;
	char input;
	vector<pair<int, char>> p;

	//입력
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> s >> input;
		p.push_back(make_pair(s, input));
	}

	//연산
	vector<char> result = makeWheel(n, p);

	//출력
	if (result[0] == '!') {
		cout << "!";
	}
	else {
		for (auto iter : result) {
			cout << iter;
		}
	}

	return 0;
}