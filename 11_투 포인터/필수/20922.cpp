#include "iostream"
#include "vector"
#include "map"

using namespace std;

int getSequence(int k, vector<int> numbers){
    int start=0, end=0;
    int length=0;
    map<int, int> n_count;  // 숫자의 개수를 세어줄 map

    // end가 numbers의 끝까지 도달할 때까지
    while(end < numbers.size()){
        // 현재 end가 가리키고 있는 숫자의 개수를 늘려준다
        n_count[numbers[end]]++;

        // 만약 k개보다 end가 가리키고 있는 숫자의 개수가 많다면
        if(n_count[numbers[end]] > k){
            // k보다 작아질때까지 start를 전진시켜줌
            // 이때 start가 앞으로 감에 의해 제외되는 숫자들에 대해서 개수 처리를 해준다.
            while (n_count[numbers[end]] > k) {
                n_count[numbers[start]]--;
                start++;
            }
        }
        // lenght 업데이트
        length = (length > (end - start + 1)) ? length : (end - start +1);
        end++;
    }
    return length;
}

int main(){
    int n, k;
    vector<int> numbers;

    // 입력
    cin >> n >> k;
    numbers.assign(n, 0);

    for(int i=0; i<n; i++){
        cin >> numbers[i];
    }

    // 연산과 출력
    cout << getSequence(k, numbers);
}