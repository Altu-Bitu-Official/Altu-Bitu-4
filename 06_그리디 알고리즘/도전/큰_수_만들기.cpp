#include <string>
#include <vector>
/*
* 결론적으로 (문자열 길이 - k)개 만큼의 숫자를 합쳐 리턴해주면 된다.
* 즉, 앞에서부터 k, k+1, ... 번째 까지의 숫자들에 대해 최댓값을 하나씩 포함시키면 된다.
* 이 때, 이미 추가한 숫자가 있다면 그 뒤에 해당하는 숫자만을 추가해야 한다.
* (앞 숫자를 추가할 경우, 최댓값이 보장되지 않음)
*/
using namespace std;

string solution(string number, int k) {
    string answer = "";
    int max_val = 0;
    int max_idx = 0;
    int idx = 0;
    while (idx < number.length()) {
        if (max_val < number[idx]) {//최댓값, 최댓값의 인덱스 갱신
            max_val = number[idx];
            max_idx = idx;
        }
        if (idx == k) {  //k: 한 번 탐색하는 인덱스의 최댓값
            // k까지 다 탐색하면, 앞서 탐색한 숫자들 중 최댓값부터 다시 탐색을 시작한다
            // (앞부분을 추가하지 않기 위함)
            idx = max_idx; 
            k++; //다음 탐색 범위 확대(k, k+1, ..., number.length() )
            answer.push_back(max_val);
            max_val = 0; //새로운 최댓값을 찾아야 하므로 최댓값 초기화
        }
        idx++;
    }
    return answer;
}
