#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calculate(int &sum, vector<int> &v_a, vector<int> &v_b, string a, string b, vector<int> &ans)
{
    // 연산, a와 b 둘 중 길이가 긴 문자열까지 반복
    for (unsigned long int i = 0; i < max(a.length(), b.length()); i++)
    {
        // 마지막 자리수 a와 b 합치기
        if (i < a.length())
        {
            sum += v_a.back();
            v_a.pop_back();
        }
        if (i < b.length())
        {
            sum += v_b.back();
            v_b.pop_back();
        }
        // 1의 자리수를 ans에 저장
        ans.push_back(sum % 10);
        // 10의 자리수를 다음 a+b로 넘겨 함께 합치기
        sum /= 10;
    }
    // 마지막 남은 10의 자리수 ans에 합쳐주기
    if (sum > 0)
    {
        ans.push_back(sum);
    }
}

int main()
{
    string a, b;
    vector<int> ans;
    vector<int> v_a, v_b;

    int sum = 0;
    // 입력
    cin >> a >> b;
    // 해당 자리수를 int형 숫자로 변환해 벡터에 저장
    for (char i : a)
    {
        v_a.push_back(i - '0');
    }
    for (char i : b)
    {
        v_b.push_back(i - '0');
    }
    //계산 함수
    calculate(sum, v_a, v_b, a, b, ans);
    //출력
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i];
    }

    /* @@@질문입니다! -> 해결했습니다 감사합니다!
    혹시 왜 아래 코드는 안 되는지 알 수 있을까요??
    제가 추측하기론 string ans에 배열 크기 문제가 있는 것 같은데,,..
    정확한 원인을 모르겠어서 질문 드려요!

    string a, b, ans;
    int sum;
    //입력
    cin >> a >> b;

    //연산, a와 b 둘 중 길이가 긴 문자열까지 반복
    for(unsigned long int i = 0; i<max(a.length(), b.length()); i++){
        //해당 자리수를 int형 숫자로 변환해 a와 b 합치기
        if(i < a.length()){
            sum += a[a.length()-i-1]-'0';       //뒤에서부터 합치기 위해 length()-i-1
        }
        if(i < b.length()){
            sum += b[b.length()-i-1]-'0';
        }
        //1의 자리수를 string ans에 저장
        ans.push_back(sum % 10 + '0');
        //10의 자리수를 다음 a+b로 넘겨 함께 합치기
        sum /= 10;
    }
    //마지막 남은 10의 자리수 ans에 합쳐주기
    if(sum > 0){
        ans.push_back(sum + '0');
    }
    //출력
    for(int i=ans.length()-1; i>=0; i--){
        cout << ans[i];
    }
    */
}