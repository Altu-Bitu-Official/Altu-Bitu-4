#include <iostream>
#include <map>
#include <string>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//테스트케이스
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++) {
		int res = 1;
		int num;
		cin >> num;
		map <string, int> t; //의상 종류, 갯수수
		string name, type;
		//의상의 이름&종류, 공백으로 구분
		for (int i = 1; i <= num; i++) {
			cin >> name >> type;
			if (t.find(type) == t.end()) t[type] = 1;
			else t[type]++;
		}
		for (auto iter = t.begin(); iter != t.end(); iter++){
			//각 타입의 옷을 입는 경우
			res *= (iter->second + 1);
		}
		//각 테스트케이스에 대한 경우의수
		cout << res - 1 << '\n';
	}