#include <iostream>
#include <vector>
#include <set>

using namespace std;

//n과 k를 받고 바퀴의 알파벳이 들어있는 벡터를 리턴하는 함수
vector<char> checkWheel(int n, int k) {
    vector<char> answer (n, ' ');
    vector<pair<char, int>> input(k - 1); //첫 줄의 숫자를 버리고 k-1번만큼 (알파벳, 숫자를) 입력받기 위해 크기를 k-1로.
    set<char> occupied; //이미 바퀴에 들어있는 알파벳을 저장하는 set
    int idx = 0, t; 
    k--; //첫 줄의 숫자를 버리고 k-1번만큼 (알파벳, 숫자를) 입력받기 위해 k--.

    //입력
    cin >> t; //첫 줄 숫자 버리기
    for (int i = 0; i < k; i++) {
        cin >> input[i].first >> input[i].second;
    }
    cin >> answer[0]; //마지막 알파벳에서 배열 시작, 따라서 따로 지정.
    occupied.insert(answer[0]); //알파벳 셋에 넣어주기

    while (k--) {
        idx = (idx + input[k].second) % n; //이동한 숫자만큼 기존 인덱스에 더한 뒤 바퀴의 크기만큼 나눈 나머지가 바뀐 인덱스.

        if (answer[idx] == ' ') { //칸이 비어있을 때
            if (occupied.find(input[k].first) == occupied.end()) { 
                answer[idx] = input[k].first;
                occupied.insert(input[k].first);
                //주어진 알파벳이 바퀴에 없다면 그대로 입력, 셋에 저장
            } else {
                answer[0] = '!';
                break;
                //있다면 answer[0] = '!', break.
            }
        } else if (answer[idx] != input[k].first) {
            answer[0] = '!';
            break;
            //칸이 차있고 입력받은 값과 칸의 알파벳이 다르다면 마찬가지로 break.
        }
    }

    return answer;
}

int main() {
    int n, k;

    //입력
    cin >> n >> k;

    //출력
    for (char c : checkWheel(n, k)) {
        if (c == '!') { 
            cout << '!';
            break;
            // ! == 바퀴 존재 불가, 따라서 ! 출력 후 프로그램 종료.
        }
        else if (c == ' ') {
            cout << '?';
        }
        else {
            cout << c;
        }
    }
}