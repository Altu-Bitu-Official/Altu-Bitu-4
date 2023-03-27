#include <iostream>
#include <vector>
using namespace std;

int main() {
	//입력
	int number;
	cin >> number;
	vector<int> planet(number, 0);//행성 담기

	for (int i = 0; i < number; i++) {
		cin >> planet[i];
	}

	//지구를 벗어나면 출발속도보다 떨어뜨릴수만 있지, 
	//높일 수는 없다.
	//계산
	//1. 거꾸로 생각하면
	//지구부터 생각-> 양의 배수여야함& 늘릴수만 있음
	//300 400 500 400 300
	//900<800<500<400<300 일케 커짐
	unsigned long long speed = planet[number - 1];//지구속도
	for (int i = number - 2; i >= 0; i--) {//꺼꾸로체크
		//나눠 떨어지지 않는 애만 건드리면 됨.
		//그 숫자와 같은게 최선인데, 근데 그 숫자와 같은 경우가 줄어드는 경우면 안됨
		//따라서 나누어떨어지지 않는데 그 숫자와 같게 할 경우 줄어들면
		//그럼 그 숫자의 n배로 적용.//while문으로 나누어떨어질때까지 n을 늘림. 나누어떨어지면 break;
		if (speed % planet[i] != 0) {
			//그 숫자와 같게 만들기.(나보다 클 때만)
			if (planet[i] > speed) {
				speed = planet[i];
			}
			//근데 그 숫자와 같게 만들경우가 지금 스피드보다 떨어지는거면?
			else {
				//몇 배 곱할지 정하기
				unsigned long long n = speed / planet[i];
				n++;//어차피 1더하면 커짐(planet[i]가 나머지보다 크니까)
				speed = planet[i] * n;
			}
		}
	}

	//출력
	std::cout << speed;

	return 0;
}