#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//비교 함수
bool cmp(string a, string b){
    int a_size=a.size(); int b_size=b.size();
    int sum;
    
    if(a_size != b_size)//1. 길이 오름차   
        return a_size < b_size;
    //길이 같을 때, 자릿수합 구하기
    int a_sum=0;    int b_sum=0;
    for (int i=0; i<a_size; i++){
        if(isdigit(a[i]))   a_sum += (a[i]-'0');
        if(isdigit(b[i]))   b_sum += (b[i]-'0');
    }
    if(a_sum != b_sum)//2. 자릿수합 오름차
        return a_sum < b_sum;
    return a < b;//3. 사전순
}

int main()
{
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);
    
    int n; 
    string input;
    vector<string> my_guitar;
    //입력
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> input;
        my_guitar.push_back(input);
    }
    //연산
    sort(my_guitar.begin(), my_guitar.end(), cmp);
    //출력
    for (int i = 0; i < n; i++){
        cout << my_guitar[i] << '\n';
    }
    
    return 0;
}