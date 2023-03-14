#include <iostream>
using namespace std;

const int MAX_NUM = 1000000;
const int MAX_TEST = 100000;

int is_prime[MAX_NUM] = {0};

//�����佺�׳׽��� ü(0,1 ����)
void eratos() {
	//2~������ MAX_NUM����
	for (int i = 2; i * i <= MAX_NUM; i++) {
		if (is_prime[i] == 0) { //i�� �Ҽ����
			for (int j = i * i; j <= MAX_NUM; j += i) {
				is_prime[j] = 1; //i�� ����� ����
			}
		}
	}
}

int goldbach(int n) { 
	for (int i = 3; i <= n; i += 2) { //3�̻� n������ Ȧ�� i�� ���ؼ�
		if (is_prime[i] == 0 && is_prime[n - i] == 0) { //i�� n-i�� ��� �Ҽ��̸�
			return i; //�� ���� ���
		}
	}
	return 0; //�������� ������ �������� ����
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int input;
	eratos();

	for(int i=0; i<MAX_TEST; i++) {
		cin >> input;
		if (input == 0) {
			break;
		}
		int div = goldbach(input);
		if (div == 0) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
		else {
			cout << input << " = " << div << " + " << input-div << "\n";
		}
	}
	return 0;
}