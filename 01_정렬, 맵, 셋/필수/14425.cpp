#include<iostream>
#include<string>
#include<map>

using namespace std;

int N, M, answer;
string word;
map<string, bool> m; 

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> word;
		m[word] = true;
	}

	for (int i = 1; i <= M; i++)
	{
		cin >> word;
		if (m[word]){
            answer++;
        } 
	}
	cout << answer ;
}