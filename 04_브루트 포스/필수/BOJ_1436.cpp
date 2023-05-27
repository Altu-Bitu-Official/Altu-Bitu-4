#include<iostream>
using namespace std;

int N, title, cnt, temp;

int main()
{
	
	cin >> N;

	title = 0; 
	cnt = 0; 

	while (cnt != N)
	{
		title++;
		temp = title;

		while (temp != 0)
		{
			if (temp % 1000 == 666)
			{
				cnt++;
				break;
			}
			else temp;
		}
	}
	cout << title;
}