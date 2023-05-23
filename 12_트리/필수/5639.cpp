#include <iostream>
#include <vector>

using namespace std;
void calOrder(int start, int end, vector<int> &v){
    if(start >= end){
        return; 
    }
    int idx = start + 1; //idx: start보다 커지는 순간 
                         //=> 오른쪽 서브트리가 됨 
    while(idx < end){ 
        if(v[start] < v[idx]){ //v[start] < v[idx] 될 때까지 idx++ 
            break;             
        }
        idx++;
    }
    calOrder(start+1, idx, v); //left 서브트리
    calOrder(idx, end, v); //right 서브트리 
    cout << v[start] << "\n"; //root 
}

int main()
{
    ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	//입력 
    int n;
    vector<int> num;
    while(cin >> n){
        num.push_back(n);
    }
    //연산 & 출력 
    calOrder(0, num.size(), num);

    return 0;
}