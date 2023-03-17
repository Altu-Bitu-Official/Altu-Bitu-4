/* substr 사용해서 고쳐보기
참고 : https://ponyozzang.tistory.com/676
*/

#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;

    for ( int i = 666; i < 2066666666; i++){
        string s = to_string(i); // 숫자 타입의 데이터를 안전하게 스트링 타입으로 변경
        int suc = 0; //연속하는 6의 개수
        for ( int j = 0; j < s.length() - 2 ; j++){
            if(s.substr(j,3) == "666"){
                N--;
                break;
            }
        }
        if ( N == 0){
            return cout << s, 0;
        }
    }
}