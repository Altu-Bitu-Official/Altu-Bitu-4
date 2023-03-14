#include<iostream>
#include<tuple>
using namespace std;


tuple<char, int>shift(string go, tuple <char, int>location) {

	tuple<char, int>origin;
	get<0>(origin) = get<0>(location);
	get<1>(origin) = get<1>(location);

	if (go == "R") {
		++get<0>(location);
	}
	else if (go == "L") {
		--get<0>(location);
	}
	else if (go == "B") {
		--get<1>(location);
	}
	else if (go == "T") {
		++get<1>(location);
	}
	else if (go == "RT") {
		++get<0>(location); ++get<1>(location);
	}
	else if (go == "LT") {
		--get<0>(location); ++get<1>(location);
	}
	else if (go == "RB") {
		++get<0>(location); --get<1>(location);
	}
	else if (go == "LB") {
		--get<0>(location); --get<1>(location);
	}

	return location;
}

int main() {

	char x; int y; int N;
	cin >> x >> y;
	tuple<char, int>king_xy = make_tuple(x, y);//ŷ�� ��ġ�� Ʃ�÷� ����
	cin >> x >> y;
	tuple<char, int>stone_xy = make_tuple(x, y);//������ ��ġ�� Ʃ�÷� ����
	cin >> N;

	string go;

	for (int i = 0; i < N; i++) {
		cin >> go;
		if (stone_xy == shift(go, king_xy)) {
			tuple<char, int> new_xy;
			new_xy= shift(go, stone_xy);
			if (get<0>(new_xy) >= 'A' && get<0>(new_xy) <= 'H' && get<1>(new_xy) >= 1 && get<1>(new_xy) <= 8) {
				stone_xy = new_xy;
			}
			//킹 위치와 스톤 위치가 같을 예정이라면 스톤을 먼저 이동
		
		}
		if (stone_xy != shift(go, king_xy)) {
			tuple<char, int> new_xy;
			new_xy = shift(go, king_xy);
			if (get<0>(new_xy) >= 'A' && get<0>(new_xy) <= 'H' && get<1>(new_xy) >= 1 && get<1>(new_xy) <= 8) {
				king_xy = new_xy;
			}
			//스톤을 이미 옮긴상황에서 스톤위치==킹위치라면 스톤을 못 옮기는 상황이라는 뜻이므로
		}
	}

	cout <<get<0>(king_xy) << get<1>(king_xy) << '\n';
	cout <<get<0>(stone_xy) << get<1>(stone_xy) << '\n';

	return 0;
}