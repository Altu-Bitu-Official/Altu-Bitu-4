/*
*예제 출력은 맞게 되는데 백준 제출시 틀림
*틀린 이유, 반례 못찾는 중
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // 입출력 속도 향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);
    
    string a, b;
    int sum;
    int crr=0;  //올림수
    int arr_a[10001], arr_b[10001];
    vector<int> answ;

    //입력 - 두 숫자를 문자열 a, b로 입력받음
    cin >> a >> b;
    //자릿수 더 큰 숫자가 a 되도록 함
    if(a.size() < b.size()) {     
        string tmp = a;
        a = b;
        b = tmp;
    }
    int a_size = a.size();  int b_size = b.size();
    //a의 높은 자릿수부터 int로 변환해서 배열 arr_a 에 저장
    for (int i = 0; i < a_size; i++){//0부터 a_size-1까지 a_size개
        arr_a[i] = a[i] - '0';
    }
    //b의 높은 자릿수부터 int로 변환해서 배열 arr_b 에 저장
    for (int i = 0; i < b_size; i++){//0부터 b_size-1까지 b_size개
        int tmp = a_size - b_size;
        arr_b[i + tmp] = b[i] - '0';
    }
    //낮은자릿수부터 연산해 answ 벡터에 넣음
    for (int i = a_size-1; i >= 0; i--){//a_size-1부터 0까지 a_size개
        sum = arr_a[i] + arr_b[i] + crr;
        if (sum<10){
            answ.push_back(sum);
            crr = 0;
        }
        else {
            answ.push_back(sum-10);
            crr = 1;
        }
    }
    //자릿수 +1 되었을 때 1 먼저 출력 (맨 앞자릿수 출력)
    if (crr == 1) {cout << 1;}  
    //answ 벡터 거꾸로 출력 (높은 자릿수부터 출력)
    for (int i = a_size-1; i >= 0; i--) {cout << answ[i] << '\n';}

    return 0;
}