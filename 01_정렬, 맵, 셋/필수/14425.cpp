#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n,m; 
    int count = 0; //집합에서 찾은 문자열 개수
    cin >> n >> m ; 
    map<string, int> string_map;

    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        string_map[str] = 1;
    }

    for(int i=0; i<m; i++){
        string search_str;
        cin >> search_str;
        if(string_map[search_str] == 1){
            count += 1 ;
        }
    }
    cout << count << '\n';

    return 0;

}

