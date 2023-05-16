// 20437 문자열 게임 2
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pos;     

// 문자열과 k를 입력받은 후
// 어떤 문자를 k개 포함하면서 해당 문자로 시작하고 끝나는 문자열의 (조건)
// 가장 짧은 길이와 가장 긴 길이를 pair의 형태로 반환한다.
pos findLength(string w, int k){
    int w_size = w.size();
    int min_length = w_size + 1;    // 조건을 만족하는 최단 문자열
    int max_length = 0;     // 조건을 만족하는 최장 문자열
    
    // 0부터 25까지 26개의 인덱스에 각각의 알파벳의 w에서의 위치를 저장
    // 예시: w = abaaaba -> alphabet[0] = {0,2,3,4,6} 
    vector<int> alphabet[26];
    for (int i=0; i<w_size; i++){
        alphabet[w[i] - 'a'].push_back(i);
    }

    for(int j=0; j<26; j++){    // 각각의 알파벳을 iterate
        int al_size = alphabet[j].size();

        // 해당 알파벳이 문자열 w에 k개 이상 있으면
        // 슬라이딩 윈도우 이용해서 최단길이와 최장길이 구한다. (윈도우 크기 = k)
        if(al_size >= k){   
            int left=0; int right=k-1;  // 윈도우 초기화
            int length; // 문자열 길이

            while(right < al_size){
                length = alphabet[j][right++] - alphabet[j][left++] + 1;
                min_length = min(length, min_length);
                max_length = max(length, max_length);
            }
        }
    }

    pos answ = {min_length, max_length};
    return answ;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;  int k;   // 문자열 게임의 개수 t, 문자열 속 어떤 문자의 개수 k
    string w;   
    pos ans;    
    cin >> t;

    // 문자열 게임을 t번 진행한다
    while(t--){     
        // 입력
        cin >> w >> k;

        // 연산
        ans = findLength(w, k);

        // 출력
        if(ans.second == 0){
            cout << -1 << '\n';
        } else{
            cout << ans.first << ' ' << ans.second << '\n';
        }
    }

    return 0;
}