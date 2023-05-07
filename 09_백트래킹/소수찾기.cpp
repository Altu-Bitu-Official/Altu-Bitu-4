// 프로그래머스 Lv.2 소수 찾기
// next_permutation()함수 사용법 익히기 : do ~ while문 이용
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool isPrime(int N){
    // step2. 만든 숫자가 소수인지 아닌지 판단해주기
    if(N == 0 || N == 1){
        return false;
    }
    for(int i = 2; i*i <= N; i++){ // 소수인지 아닌지 판별해주는 알고리즘
    //(에라토스테네스의 체는, N이하의 모든 소수를 구하는 알고리즘이기 때문에 이 경우는 그냥 소수 판별 알고리즘이다.)
        if(N % i == 0){
            return false;
        }
    }
    return true;
}

void makeAll(vector<char> &vec, vector<int> &nums) {
    // step1. 해당 숫자들로 모든 경우의 수 만들기
    do {
        string st;
        for(int i = 0; i < vec.size(); i++){
            st.push_back(vec[i]);
            nums.push_back(stoi(st)); //string형에서 int형으로 변환해 저장
        }
    } while(next_permutation(vec.begin(), vec.end()));
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end()); 
    // 중복값 삭제
}

int solution(string numbers) {
    int answer = 0;
    vector<char> vec;
    vector<int> nums; // 모든 경우의 수 담을 벡터 선언
    for(int i = 0; i < numbers.size(); i++){
        vec.push_back(numbers[i]);
    }
    sort(vec.begin(), vec.end()); //next_permutation()이용할 때는 우선 오름차순 정렬해놓고 시작하기.
    makeAll(vec, nums);
    for(int i = 0; i < nums.size(); i++){
        if(isPrime(nums[i])){
            answer++;
        }
    }
    return answer;
}
}
