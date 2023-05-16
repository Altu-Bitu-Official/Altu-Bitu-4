#include "iostream"
#include "vector"

using namespace std;

const int alphabet_num = 26;
const int MAX = 2147483647;

pair<int, int> getResult(string w, int k){
    int short_seq = MAX, long_seq = 0;
    vector<vector<int>> count(alphabet_num, vector<int>(0));

    // 문자열 내의 각 문자의 위치를 저장
    for(int i=0; i<w.size(); i++ ){
        count[w[i]- 'a'].push_back(i);
    }

    for(int i=0; i < alphabet_num; i++){
        // 문자의 개수가 k보다 작다면 조건을 만족할 수 없으므로 패스
        if(count[i].size() < k){
            continue;
        }
        int start=0, end=k-1;
        int tmp_short = MAX, tmp_long = 0;
        // k보다 크다면
        // 똑같은 문자로 시작하고 끝나는 문자열중 가장 짧은 것이 첫번째 결과가 될 것이고
        // 똑같은 문자로 시작하고 끝나는 문자열중 가장 긴 것이 두번째 결과가 될 것이다.
        while(end < count[i].size()){
            tmp_short = (tmp_short < count[i][end] - count[i][start] + 1) ? tmp_short : count[i][end] - count[i][start] + 1;
            tmp_long = (tmp_long > count[i][end] - count[i][start] + 1 ) ? tmp_long : count[i][end] - count[i][start] + 1;
            start++, end++;
        }
        short_seq = (short_seq < tmp_short) ? short_seq : tmp_short;
        long_seq = (long_seq > tmp_long) ? long_seq :tmp_long;
    }
    // 조건을 만족하지 못하는 경우에는 -1
    if(short_seq == MAX || long_seq == 0){
        return {-1, -1};
    }
    return {short_seq, long_seq};

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, k;
    string w;
    pair<int, int> result;

    // 입력
    cin >> t;
    while(t--){
        cin >> w;
        cin >> k;
        // 연산
        result = getResult(w, k);

        // 출력
        if(result.first == -1){
            cout << -1;
        }
        else{
            cout << result.first << " " << result.second;
        }
        cout << '\n';
    }
}