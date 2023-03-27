#include <iostream>
#include <vector>
using namespace std;

int main() {
	//입력
	int number;
	cin >> number;
	vector<int> planet(number,0);
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
	unsigned long long speed=planet[number-1];//지구속도
	for (int i = 0; i < number; i++) {
		//나누어떨어지지 않으면 늘릴수밖에 없음
		//그 숫자와 같은게 최선인데, 근데 그 숫자와 같은 경우가 줄어드는 경우면 안됨
		//따라서 나누어떨어지지 않는데 그 숫자와 같게 할 경우 줄어들면
		//그럼 그 숫자의 n배로 적용.//while문으로 나누어떨어질때까지 n을 늘림. 나누어떨어지면 break;
		
		if ((planet[i] % speed) != 0) {//나누어떨어지지않으면?
			//그 숫자와 같게 만들기.(나보다 클 때만)
			if (planet[i] > speed) {
				speed = planet[i];
			}
			//근데 그 숫자와 같게 만들경우가 지금 스피드보다 떨어지는거면?
			else {
				unsigned long long back_up = speed;
				speed = planet[i];
				unsigned long long n = speed;
				while (1) {//계속 작으면? 커질때까지 반복
					if (planet[i] <= speed && speed >= back_up) {
						break;
					}
					//작으면 지금 숫자의 n배로 적용
					speed += n;
				}
			}			
		}
	}

	//출력
	cout << speed;

	return 0;
}