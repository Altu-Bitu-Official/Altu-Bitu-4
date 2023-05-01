// 프로그래머스 Lv.2 소수 찾기
// next_permutation()함수 사용법 익히기 : do ~ while문 이용
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool isPrime(int N){
    if(N == 0 || N == 1){
        return false;
    }
    for(int i = 2; i*i <= N; i++){ // 에라토스테네스의 체
        if(N % i == 0){
            return false;
        }
    }
    return true;
}

void makeAll(vector<char> &vec, vector<int> &nums) {
    do {
        string st;
        for(int i = 0; i < vec.size(); i++){
            st.push_back(vec[i]);
            nums.push_back(stoi(st));
        }
    } while(next_permutation(vec.begin(), vec.end()));
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end()); // 중복값 삭제
}

int solution(string numbers) {
    int answer = 0;
    vector<char> vec;
    vector<int> nums; // 모든 경우의 수 담을 벡터 선언
    for(int i = 0; i < numbers.size(); i++){
        vec.push_back(numbers[i]);
    }
    sort(vec.begin(), vec.end());
    makeAll(vec, nums);
    for(int i = 0; i < nums.size(); i++){
        if(isPrime(nums[i])){
            answer++;
        }
    }
    return answer;
}