#include <iostream>
#include <set>

using namespace std;

/*
* set::find 함수 사용 (key 값이 존재하면 해당 iterator, 존재하지 않으면 set::end 반환)
* vector를 이용하면 원소를 탐색하면 시간 복잡도가 O(n) (시간 초과)
* set은 이진트리 구조를 사용하므로 원소 탐색의 시간 복잡도가 O(log2n)
* 1. find 함수 사용
* 2. count 함수 사용
*/

int main()
{
	int n, m, cnt = 0; //변수 n, m, cnt를 선언, 이때 cnt는 일치하는 문자열의 개수로 0으로 초기화함
	set<string> s; //string으로 이루어진 set s를 선언
	string input; //string형의 input 변수 선언
	// 입력
	cin >> n >> m; //n, m을 사용자로부터 입력받음
	while (n--) { //  n=0이 되면 반복문을 빠져나옴-> n개를 입력받게 됨
		cin >> input; //사용자로부터 집합 s의 문자열을 입력받음,
		s.insert(input); // set에 원소 추가
	}
	// 연산
	while (m--) { //  m=0이 되면 반복문을 빠져나옴-> m개를 입력받게 됨
		cin >> input; //사용자로부터 비교할 문자열을 입력받아 input에 저장
		// 1. find 함수 사용
		if (s.find(input) != s.end()) { // input을 찾은 위치와 자료의 끝이 일치하지 않음=set에 원소가 포함되어 있음
			cnt++; //일치하는 문자열을 찾았으니 cnt를 증가시킴
		}
		//  2. count 함수 사용
		// cnt += s.count(input); // set에 해당 원소의 존재 여부를 int형으로 리턴<-있을시 1리턴, 위의 방법 말고 이 방법도 사용 가능
	}
	// 출력
	cout << cnt << '\n';//일치하는 문자열의 수 cnt를 출력함
	return 0;
}