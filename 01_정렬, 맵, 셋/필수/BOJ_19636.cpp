#include <iostream>
using namespace std;

int main() {
	// your code goes here
	
	//입력
	int w0, l0, t;
	int d, l, a;
	
	cin >> w0 >> l0 >> t;
	cin >> d >> l >> a;
	
	//연산
	int w1 = w0;
	int w2 = w0;
	int l1 = l0;
	
	for(int i=0; i<d; i++){
	    //체중 변화
	    w1 += l-(l0+a);
	    w2 += l-(l1+a);
	
		if(abs(l-(l1+a))>t){
		    //기초 대사량 변화(체중 변화 다음에 발생)
		    l1 += ((l-(l1+a))/2.0);
		}
	}

	
	//출력: 일일 기초 대사량 l의 변화 반영 x
	if(l0<=0 || w1<=0){
	    cout << "Danger Diet\n";
	}
	else{
	    cout << w1 << " " << l0 << "\n";
	}
	
	//출력: 일일 기초 대사량 l의 변화 반영 o
	if(l1<=0 || w2<=0){
	    cout << "Danger Diet\n";
	}
	else{
	    cout << w2 << " " << l1 << " ";
	    if(l0>l1){
	        cout << "YOYO";
	    }
	    else{
	        cout << "NO";
	    }
	}
	
	
	return 0;
}

