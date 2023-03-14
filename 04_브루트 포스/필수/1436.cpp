#include <iostream>
#include <vector>

using namespace std;

int main(){

    int n; //입력받을 숫자
    cin >> n;
    vector<int> tripleSix;//종말숫자 저장할 벡터
    int i=666; //첫번째 종말 숫자 저장
while(true){ //i를 하나씩 증가시키며 i에 666이 포함됐을 경우 tripleSix배열에 저장
    if(to_string(i).find("666")!= std::string::npos){
        tripleSix.push_back(i);
    }
    if(tripleSix.size()==n){ //원하는 갯수만큼의 종말숫자가 저장되었다면 while문 break
        break;
    }
    i++;
}
cout << tripleSix[n-1];

    return 0;
}