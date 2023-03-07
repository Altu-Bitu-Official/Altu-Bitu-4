#include <iostream>
#include <vector>

using namespace std;

bool checkDuplicate(vector<char> arr) { // 배열 안에 같은 문자가 있는지 확인하는 함수
    for (int i = 0; i < arr.size() - 1; i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] != '?' && arr[i] == arr[j]) {
                cout << "!";
                return true;
            }
        }
    }
    return false;
}

void createWheel(int size, int spin_num) {
    vector<char> wheel(size,'?'); // ?으로 초기화

    int change_num; // 숫자가 바뀐 횟수
    char alphabet;
    int index = 0;  // 접근할 인덱스
    for(int i = 0; i < spin_num; i++) {
        cin >> change_num >> alphabet;
        index -= change_num % size;                
        index = index >= 0 ? index : size + index; // 계산된 인덱스가 음수이면 배열의 크기를 더해줌
        if(wheel[index] == '?' || wheel[index] == alphabet) { // 칸이 비어있거나 같은 문자로 채워져 있으면
            wheel[index] = alphabet;                          // 해당 문자로 칸을 채움
        }
        else { // 칸이 다른 문자로 이미 채워져 있다면 해당하는 바퀴 없음
            cout << "!";
            return;
        }
    }   

    if(checkDuplicate(wheel)) { // 바퀴에 같은 알파벳이 있다면 해당하는 바퀴 없음
        return;
    }

    // index부터 바퀴 차례대로 출력
    for(int i = 0; i < size; i++) {
        cout << wheel[(index + i) % size];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int size, spin_num; // 바퀴의 크기, 돌린 횟수
    cin >> size >> spin_num;
    
    createWheel(size, spin_num);

    return 0;
}