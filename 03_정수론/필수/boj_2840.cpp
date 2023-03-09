#include <iostream>  // 입출력을 위한 헤더 선언
#include <vector>    // 벡터를 위한 헤더 선언 

using namespace std;    // namespace 사용 

typedef pair<int, char> ci;   //바퀴가 몇 칸 돌았는지(int), 그때 어떤 알파벳을 가리키는지 (char) 두 가지를 담기 위해 typedef로 만들고 ci라고 네이밍 
const int ALPHA = 26;         // 알파벳의 갯수를 상수로 지정 

/*
    [2840 행운의 바퀴 ver1]
    - 문제에서 주어진대로 화살표를 고정시키고, 바퀴를 시계방향으로 돌려서 문제를 푼다.
    - 배열을 ?로 초기화 해주고, 입력한대로 처리한다
    - 바퀴를 배열로 보고 시계방향으로 바퀴를 회전시키면, 화살표가 가리키고 있는 배열의 원소는 인덱스가 감소하는 것처럼
   보인다.
    <주의 사항>
    1. ?이 아닌 문자가 저장되어있는데, 다른 문자를 저장하려는 경우
    2. 룰렛에 중복되는 문자가 있는 경우
    ** 바퀴를 돌리는 횟수가 매우 클 수도 있다. 이 부분을 유의하여 인덱스를 처리하자!
    ex) n=3 인데, 바퀴를 10번 돌릴수도 있다.
*/

// 특정 화살표에서 시작한 행운의 바퀴 시계방향으로 리턴을 위한 함수 
string arrowStartWheel(int index, int n, vector<char> &wheel) {  //가리키고 있던 index, 원판 크기, 원판의 내용을 인자로 받음 
    string ans = "";   // 정답 문자열을 ans로 선언 
    
    //ans에 정답을 하나씩 넣기 위해 for문 선언 
    for (int i = 0; i < n; i++) {  
        ans += wheel[(i + index) % n];    //시계 방향으로 출력 하기 위해 i에 index를 더해줌 -> 아래에서 index를 음수로 계산 했기 때문에 더해줌 
    }

    return ans;    //정답 문자열 반환 
}

string makeWheel(int n, vector<ci> &record) {   // 행운의바퀴 원판을 만들기 위한 함수 선언
    vector<char> wheel(n, '?');              //바퀴의 배열을 ?로 초기화 -> 나중에 채워지지 않은 칸을 채워야하는 일을 하지 않으려고 미리 ?로 초기화 함  
    vector<bool> is_available(ALPHA, false); // 알파벳 중복 체크

    int index = 0; // 화살표가 가리키는 인덱스

    //입력받은 내용을 하나하나 꺼내서 판단을 해야해서 for 문 작성
    for (int i = 0; i < record.size(); i++) {  
        int rot = record[i].first;   // rot에 바퀴가 몇 칸 돌았는지 저장 
        int ch = record[i].second;   // ch에 바퀴가 몇 칸 돌았을 때의 알파벳 저장 
        // 바퀴 돌리기위해 
        index = (index - rot + 100 * n) % n;  // 인덱스가 계속 돌거기 때문에 식을 씀. 이때 100을 곱하지 않으면 index 값이 여전히 음수일 수 있기 때문에 적당히 큰 값인 100을 곱해줘서 항상 양수가 되게 만듦
                                              // 이 문제에서는 50으로 해도 잘 나옴 
        //바퀴에 있는 알파벳 판단 시작
        if (wheel[index] == ch) {  //index가 가리키는 칸의 글자가 입력받은 문자가 같으면 문제 없음 즉, 비어있지 않지만 그 칸의 문자가 입력받은 칸의 글자와 같은 경우
            continue;              //문제 없으니까 continue로 진행 
        }

        // 주의사항 체크
        // 원판의 해당 위치에 다른 문자가 저장되어있거나, 이미 다른 곳에 문자가 사용된 경우
        if (wheel[index] != '?' || is_available[ch - 'A']) {   // index가 가리키는 칸이 비어있지 않으면서 이미 알파벳을 사용한 경우  
            return "!";   // !출력 
        }

        //비어있는 경우 
        wheel[index] = ch;             // 원판에 기록
        is_available[ch - 'A'] = true; // 알파벳 사용을 표시
    }

    return arrowStartWheel(index, n, wheel);  //출력을 위한 함수 호출 
}

int main() {
    // 입력
    int n, k;       // 바퀴의 칸의 수를 n, 바퀴를 돌리는 횟수를 k 변수에 저장 
    cin >> n >> k;  // 입력 받기 

    vector<ci> record(k, {0, 0}); // 바퀴 회전 기록을 위해 k개를 입력 받고 초깃값을 {0,0}으로 벡터 선언 
    // 벡터에 값을 입력하기 위해 반복문 
    for (int i = 0; i < k; i++) {     // 바퀴를 돌리는 횟수 k개만큼 입력 받기  
        cin >> record[i].first >> record[i].second;  // 벡터에 차근차근 입력 받기 
    }

    // 출력
    cout << makeWheel(n, record);  // makeWheel 함수 호출 
    
    return 0;   //메인 함수 종료 
}