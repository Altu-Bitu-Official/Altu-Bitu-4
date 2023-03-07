#include <stdio.h>
#include <iostream>
using namespace std;
 
void che(bool arr[], int size)
{
	arr[0] = true;
	arr[1] = true;
	
	for (int i = 2; i * i < size; i++){
		if (arr[i] == true)
			continue;
		for (int j = i * i; j < size; j += i){
			arr[j] = true;
		}
	}
}
 
int main()
{
	bool* arr = new bool[1000001];
	che(arr, 1000001);
	int n;
	bool hasAns = false;
	while (scanf("%d", &n ) != EOF){
		if(n == 0) break;
		
		for(int i = 3; i < n; i+=2){
			if(!arr[i] && !arr[n - i] ){
				hasAns = true;
				printf("%d = %d + %d\n", n, i, n - i);
				break;
			}
		}
		
		if(!hasAns)
			printf("\nGoldbach's conjecture is wrong.\n");
	}
}