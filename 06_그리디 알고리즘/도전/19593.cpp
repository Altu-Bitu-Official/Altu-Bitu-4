#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

bool isPossible(vector<int> &trees, int sum){
    if(sum%3){
        return false;
    }
    std::sort(trees.begin(), trees.end());
    pair<int,int> count(0,0); // first:1 second:2
    int tmp= 0;

    for(int i=0; i<trees.size(); i++){
        trees[i] -= (3-tmp);
        tmp = trees[i]%3;
    }
    if(tmp){
        return false;
    }
    return true;
}

int main(){
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n, tmp, sum =0;
    vector<int> trees;
    cin >> n;
    while(n--){
        cin >> tmp;
        sum += tmp;
        trees.push_back(tmp);
    }

    // 연산과 출력
    if(isPossible(trees,sum)){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}