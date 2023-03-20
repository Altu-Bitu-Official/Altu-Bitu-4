#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int ALPHA = 26; // 알파벳 수

// 바퀴를 출력하는 함수
string printWheel(vector<char> wheel, int index, int size) {
    string ans = "";
    // index부터 바퀴 차례대로 출력
    for(int i = 0; i < size; i++) {
        ans += wheel[(index + i) % size];
    }
    return ans;
}

string createWheel(int size, int spin_num) {
    vector<char> wheel(size,'?'); // ?으로 초기화
    vector<bool> is_used(ALPHA, false); // 알파벳 중복 체크

    int change_num; // 숫자가 바뀐 횟수
    char alphabet;
    int index = 0;  // 접근할 인덱스
    for(int i = 0; i < spin_num; i++) {
        cin >> change_num >> alphabet;
        index -= change_num % size;                
        index = index >= 0 ? index : size + index; // 계산된 인덱스가 음수이면 배열의 크기를 더해줌

        if(wheel[index] == alphabet) { // 해당 자리에 같은 문자가 이미 저장되어 있으면 넘어감
            continue;
        }

        if(wheel[index] != '?' || is_used[alphabet - 'A']) { // 다른 문자가 채워져있거나 해당 문자가 이미 사용된 경우
            return "!";                                      // 해당하는 바퀴 없음 -> '!' 출력
        }

        wheel[index] = alphabet;         // 바퀴 인덱스 해당 문자로 채우기
        is_used[alphabet - 'A'] = true;  // 사용되었는지 표시
    }   
    return printWheel(wheel, index, size);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int size, spin_num; // 바퀴의 크기, 돌린 횟수
    cin >> size >> spin_num;
    
    cout << createWheel(size, spin_num); // 결과 출력

    return 0;
}