#include <iostream>
#include <string>

using namespace std;

void GetNumber(string& position, int& x, int& y)
{
	x = position[1] - '0';
	y = position[0] - 'A' + 1;
}


bool CheckLocation(int x, int y) {
	if (x <= 8 && x >= 1 && y <= 8 && y >= 1) {
		return true;
	}
	else {
		return false;
	}
}

void getPosition(char& input, int& num, int& alph) {
	switch (input)
	{
	case 'R':
		alph++;
		break;
	case 'L':
		alph--;
		break;
	case 'B':
		num--;
		break;
	case 'T':
		num++;
		break;
	default:
		break;
	}
}

void setCoor(string& position, int x, int y) {
	position[0] = 'A' + y - 1;
	position[1] = x + '0';
}

int main() {
	string k_position, s_position;
	int n;
	string input;
	cin >> k_position >> s_position >> n;
	int k_numb, k_alph;
	int s_numb, s_alph;
	GetNumber(k_position, k_numb, k_alph);
	GetNumber(s_position, s_numb, s_alph);
	for (int i = 0; i < n; ++i) {
		int num = 0, alph = 0;
		cin >> input;
		for (int j = 0; j < input.length(); ++j) {
			getPosition(input[j], num, alph);
		}
		if (CheckLocation(k_numb + num, k_alph + alph)) {
			string ok_position = k_position;
			int ok_al = k_alph;
			int ok_no = k_numb;
			k_alph += alph;
			k_numb += num;
			setCoor(k_position, k_numb, k_alph);
			if (k_position == s_position) {
				if (CheckLocation(s_numb + num, s_alph + alph)) {
					s_alph += alph;
					s_numb += num;
					setCoor(s_position, s_numb, s_alph);
				}
				else {
					k_position = ok_position;
					k_alph = ok_al;
					k_numb = ok_no;

				}
			}
		}
	}
	cout << k_position << "\n";
	cout << s_position << "\n";
	return 0;
}