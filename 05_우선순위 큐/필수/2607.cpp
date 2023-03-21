#include <iostream>
#include <algorithm>
using namespace std;


int main(){
    ios ::sync_with_stdio(0);
    cin.tie(0);

    //입력
    int n;
    cin >> n;
    string base, cmp;
    cin >> base;

    //연산
    int alpha[26] = {0, }; //알파벳 구성
    int base_len = base.size(); //알파벳 길이
    for(int i=0; i<base_len; i++){
        alpha[base[i]-'A'] += 1; //alpha배열에 각 알파벳의 개수를 넣음
    }

    int cnt=0;
    for(int i=0; i<n-1; i++){
        cin >>cmp;
        int cmp_len = cmp.size();
        int cmp_copy[26];
        copy(alpha, alpha+26, cmp_copy); //배열 복제

        int same=0;
        for(int i=0; i<cmp_len; i++){
            if(cmp_copy[cmp[i]-'A']>0){
                cmp_copy[cmp[i]-'A']--;
                same++;
            }
        }
        if(base_len == cmp_len){
            if(same == base_len || same == base_len -1){
                cnt++; //문자 구성이 같거나, 한 글자만 다른 경우
            }
        }
        //기준 문자열이 한 글자 길면 한 글자 추가
        else if(base_len -1 == cmp_len && same == base_len -1)
            cnt++;
        //기준 문자열이 한 글자 짧으면 한 글자 삭제
        else if(base_len+1 == cmp_len && same == base_len)
            cnt++;
        else continue;
    }

    //출력
    cout << cnt << '\n';
}