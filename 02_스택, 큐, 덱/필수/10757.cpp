//스택 사용
#include <iostream>
#include <stack>
using namespace std;

/*
    매개변수에 &를 붙이면 원본을 참조하게 됩니다.
    **이 문제에서는 굳이 참조자를 사용할 필요는 없지만, C++에서는 주로 &를 붙입니다**
*/
stack<int> calcPlus(string &a, string &b) {//인자: 원본참조(string: 힙공간). Question : 그러니까, main속 string변수 자체 주소가 아니라 힙공간을 가리키게 된다는 것인가요? 어떻게 이렇게 되는건가요? 참조 변수(a,b) 안에 힙에 할당된 원본 주소가 들어있는것으로 아는데, &a라고 하니 a자체의 주소라고 느껴져서 헷갈립니다. 왜 a가 아니라 &a인지 헷갈리는데, 원본참조라고 정의하면 납득되긴 합니다. 근데 원래 배우던 거랑 달라서, 헷갈립니다. c++에서는 다른건가요? 질문이 너무 장황하네요 죄송합니다 ㅠ,ㅠ 
    int idx_a = a.size() - 1; // 일의 자리 인덱스. 배열이니까 인덱스 젤 큰게 젤 꼭다리임
    int idx_b = b.size() - 1; // 일의 자리 인덱스. 배열이니까 인덱스 젤 큰게 젤 꼭다리임
    bool carry = false; //올림수 있는지 체크(10이상이면 올림수 true)
    stack<int> ans;//답안 저장 스택

    while (idx_a >= 0 && idx_b >= 0) {
		//아스키코드 보면 '0' 빼면 숫자 나옴
		//idx_a--: 인덱스를 뺀다는 건 그 다음 자릿수로 옮겨간다는 것. 배열이니까
        //num에 그 자릿수에서 둘이 더한거 저장한다.
		int num = (a[idx_a--] - '0') + (b[idx_b--] - '0'); // 문자를 숫자로 바꾸어 더하기, 그리고 인덱스 변경

        num += carry;       // num에 carry 더해주기. (carry는 어차피 1 아니면 0). //따라서 초기값 false니까 반복문 첨이면 상관없음. 나중엔 carry값이 업데이트됨 (전 자릿수에서 캐리: 다음 자릿수에선 1이 추가되는 셈)
        carry = num / 10;   // num의 값이 10이상이면 carry가 1, 아니면 0 //9+9: '1'8 
        ans.push(num % 10); // 올림을 제외한 값만 스택에 push //그 자릿수의 결정된 수를 스택에 push함.
    }

    // a에서 남은 숫자 반영
    while (idx_a >= 0) {//인덱스 남았으면(b먼저 끝난 상황)
        int num = a[idx_a--] - '0';// 그 자릿수 숫자 구하고

        num += carry;//캐리가 저 위에 while문 지역변수가 아니라서 b의 [0]으로 끝났어도 저장된 상태. 따라서 그 carry 를 num에 저장함
        carry = num / 10;// num의 값이 10이상이면 carry가 1, 아니면 0 //9+9: '1'8 
        ans.push(num % 10);// 올림을 제외한 값만 스택에 push //그 자릿수의 결정된 수를 스택에 push함.
    }

    // 남은 올림 확인
    if (carry)//a의 [0]에서 또 올림수가 있는경우
        ans.push(1);//그러면 맨 앞자리수에 1 올려줌(carry)

    return ans;//답안 스택 리턴함
}

int main() {
    ios::sync_with_stdio(0);//시간초과방지//Question: 시간초과방지 코드 맞나요? 기억이 가물가물하네요
    cin.tie(0);//시간초과방지

    string a, b;//입력 숫자 두 개 저장, 그 크기 자료형이 없어서 string으로 받는다. 
    stack<int> ans;//답안을 스택으로 쌓고 출력(맨 앞자리 수가 젤 먼저 출력되어야 하니까)
	

    //입력
    cin >> a >> b;//a, b입력받는다. 

    //연산
    if (a.length() < b.length()) // b의 길이가 더 길다면
        swap(a, b);//긴게 a로 가도록

    ans = calcPlus(a, b);//답 스택 저장

    //출력(탑 출력&팝 반복)
    while (!ans.empty()) {//답이 있으면
        cout << ans.top();//탑 출력
        ans.pop();//팝
    }
}