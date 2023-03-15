#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n,sum;
    int num1[100001], num2[100002];
    string a, b;
    vector<int> vec;
    cin >> a >> b;

    if(a.size() < b.size()){
        swap(a,b);
    }

	for(int i=0; i<a.size(); i++)
		num1[i+1] = a[i] - '0';
	
	for(int i=0; i<b.size(); i++)
		num2[i + 1 + (a.size()-b.size())] = b[i] - '0';

	for(int i=a.size(); i>0; i--)
	{
		sum = num1[i] + num2[i];
		if (sum >= 10)
		{
			num1[i - 1]++;
			sum -= 10;
		}
		vec.push_back(sum);
	}


	if (num1[0] != 0) cout << 1;

	for (int i = vec.size() - 1; i >= 0; i--)
	{
		cout << vec[i];
	}
	
	return 0;
}