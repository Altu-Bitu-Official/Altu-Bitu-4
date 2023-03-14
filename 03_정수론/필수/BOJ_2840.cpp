#include <iostream>
#include <vector>//바퀴의 칸을 벡터로.

using namespace std;

int main() {
    int n, k;//바퀴의 칸 수, 바퀴를 돌리는 횟수
    cin >> n >> k;

    vector<char> wheel(n,' ');//결정지을 바퀴의 틀 만들고 초기화
    int index = 0;//회전에 따라 변화하는, 화살표가 가리키는 바퀴 칸의 인덱스. 처음에 0에서부터 시작.

    //k회만큼 반복하며 바퀴에 문자 넣기, (인덱스 늘려감)
    for (int i = 0; i < k ;i++) {
        
        int s;//1회당 글자가 바뀐 횟수
        char content = ' ';//문자
        cin >> s >> content;

        index += s;
        index %= n;

        if (wheel[index] != ' ' && wheel[index] != content) {//비어있지 않은데, 이전의 글자와 새로운 글자가 다른 경우.
            cout << "!\n";
            exit(0);
        }
        else {
            
            wheel[index] = content;
        }

              

    }

    //벡터를 순회하여 겹치는 문자가 있는 경우 !를 출력하고 종료
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (wheel[i] != ' ' && wheel[i] == wheel[j]) {
                cout << "!\n"; 
                exit(0);                
            }
        }
        

    }

    //문제가 없는 경우 마지막으로 머물렀던 인덱스에서부터 처음 글자를 넣었던 방향과 반대 방향으로 문자 출력(인덱스 줄여감)
        for (int i = 0; i < n;i++) {
            if (wheel[index] == ' ') {
                cout << '?';
            }
            else {
                cout << wheel[index];

            }

            index--; 

            if (index < 0) {
                index += n;
                           }

        }
        return 0;
    




}