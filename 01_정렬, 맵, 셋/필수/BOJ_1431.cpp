#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string& a, string& b){
    //1.길이 비교
    if(a.length() != b.length()){
        return a.length() < b.length();
    }
    //2.합 비교
    int a_sum=0, b_sum=0;
    for(int i=0; i<a.length(); i++){
        if('0'<=a[i] && a[i]<='9') a_sum += a[i] - '0';
        if('0'<=b[i] && b[i]<='9') b_sum += b[i] - '0';
    }
    if(a_sum != b_sum){
        return a_sum < b_sum;
    }
    //3.사전순
    return a<b;
    
}

int main() {
    
    //입력
    int n;
    cin >> n;
    vector<string> serial_num(n) ;
    for(int i=0; i<n; i++){
        cin >> serial_num[i];
    }
    // 연산
	sort(serial_num.begin(), serial_num.end(), cmp);
	//연산은 str sort 함수 이용
	
	//출력
    for(int i=0; i<n; i++){
        cout << serial_num[i] << "\n";
    }
    
    
    return 0;
}