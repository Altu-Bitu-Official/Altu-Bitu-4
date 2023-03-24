#include <iostream>
#include <vector>
#include <string>

using namespace std;
typedef pair<char, char> cc;

bool checkPos(cc pos) {
    if (pos.first < 'A' || pos.first > 'H'
		|| pos.second < '1' || pos.second > '8') {
		return false;
	}
	return true;
}

void moveByInput(string input, char &x, char &y) { // 이동 함수 x : 열, y : 행
	for (int i = 0; i < input.size(); i++) {
		char how = input[i];
		if (how == 'R') {
			x++;
		}
		else if (how == 'L') {
			x--;
		}
		else if (how == 'B') {
			y--;
		}
		else { // T
			y++;
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cc k, s; // 킹과 돌
    int move_num;      // 움직이는 횟수
    
    cin >> k.first >> k.second >> s.first >> s.second >> move_num;
    
    string input; // 이동 입력
    for(int i = 0; i < move_num; i++) {
        cc k_origin = k; // 원래 위치 저장
        cc s_origin = s;
        cin >> input;
        
        moveByInput(input, k.first, k.second); // 입력에 따라 king과 rock 이동

        if(k.first == s.first && k.second == s.second) {
            moveByInput(input, s.first, s.second);
        }

        if(!checkPos(k) || !checkPos(s)) { // 하나라도 범위를 벗어나면
            k = k_origin; // 원래 위치로 되돌림
            s = s_origin; 
        }
    }
    
    // 결과 출력
    cout << k.first << k.second <<'\n'<< s.first << s.second;
    return 0;
}