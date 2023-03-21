#include<iostream>
#include<vector>
#include<algorithm>   //참고 : https://unluckyjung.github.io/cpp/2020/04/24/Set_Func/
#include <string>

using namespace std;


int main(){
    int n, count=0;
    cin >> n;  //입력될 단어의 개수
    string word;
    cin>> word;

    vector<char> vec(word.begin(), word.end()); //string을 char vector
    sort(vec.begin(), vec.end()); // 오름차순으로 정렬

    for (int i=0; i<n-1;i++){ //본격적인 비교
        string str;
        cin >> str;

        vector<char> strvec(str.begin(), str.end());
        sort(strvec.begin(), strvec.end()); // 오름차순으로 정렬

        if (vec.size() == strvec.size()){ 
            vector<char> buff(vec.size() + strvec.size());
            auto iter = set_union(vec.begin(), vec.end(), strvec.begin(), strvec.end(), buff.begin());
            buff.erase(iter, buff.end());
            if( vec.size() == buff.size() || vec.size()+1 == buff.size()){
                count+=1;
            }
        }
        else if (vec.size() -1 == strvec.size()){ // vec 사이즈가 1 더 큰 경우
            vector<char> buff(vec.size() + strvec.size()); //합집합
            auto iter = set_union(vec.begin(), vec.end(), strvec.begin(), strvec.end(), buff.begin());
            buff.erase(iter, buff.end());
            if ( buff == vec){
                count+=1;
            }

        }
        else if (vec.size()  == strvec.size() -1){ // vec에 하나 추가한 경우
            int size = vec.size();
            swap(vec, strvec);
            vector<char> buff(vec.size() + strvec.size()); // 합집합
            auto iter = set_union(vec.begin(), vec.end(), strvec.begin(), strvec.end(), buff.begin());
            buff.erase(iter, buff.end());
            if ( size+1 == buff.size()){
                count +=1;
            }
        }

    }
    cout << count;
    return 0;
}