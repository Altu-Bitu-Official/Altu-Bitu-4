#include <iostream>
#include <vector>

using namespace std;
#define ALPHA 26 // 알파벳 개수

void storeString(string &str, vector<int> &alpha) { // 문자열을 알파벳 개수별로 저장
    for(int i = 0; i < str.size(); i++) { 
        int idx = str[i] - 'A';
        alpha[idx]++;  // 각 알파벳 자리의 수를 1만큼 증가
    }
}
// 비슷한 단어인지 확인해주는 함수
bool isSimilar(int ori_size, vector<int> origin, string &compare) {
    int check = 0; // 같은 문자의 개수를 저장
    int comp_size = compare.size();
    for(int i = 0; i < comp_size; i++) { // 비교할 문자열을 돌며 origin과 같으면 check에 저장
        int idx = compare[i] - 'A';
        if(origin[idx] > 0) {
            check++;
            origin[idx]--;
        }
    }
    // 문자열의 길이가 같으면 size-1개 이상 같아야 함
    if((ori_size == comp_size) && (check >= ori_size - 1)) { 
        return true;
    }
    // 문자열의 길이 차이가 1이면 작은 길이만큼 같아야 함
    else if(abs(ori_size - comp_size) == 1 && check == min(ori_size, comp_size)) {
        return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //입력
    int n, cnt;
    string first, input;
    cin >> n;     // 입력받을 문자열의 개수
    cin >> first; // 첫 번째 문자열

    vector<int> alpha(ALPHA, 0);  // 알파벳별 개수를 저장할 벡터 (계속 오류가 났던 이유: 초기화를 안 해서)
    storeString(first, alpha); // 첫 번째 문자열에 어느 문자가 몇 개 있는지 저장

    for(int i = 1; i < n; i++) { // 두 번째 문자부터
        cin >> input;
        if(isSimilar(first.size(), alpha, input)) { // 첫 번째 문자열과 비슷한 문자열인지 확인
            cnt++;
        }
    }

    // 결과 출력
    cout << cnt; 
    return 0;
}