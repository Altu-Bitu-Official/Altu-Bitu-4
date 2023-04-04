#include <iostream>
#include <vector>

using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int w, h, block_count;
    cin >> w >> h >> block_count;
    vector<int> v(w * h);
    int arr[257] = {0,};

    //입력
    for (int i = 0; i < w * h; i++) {
        int block;
        cin >> block;
        v[i] = block;
    }

    int final_t = 0, final_h = 0;

    for (int i = 0; i < 257; i++) {
        int t = 0;
        int my_block = block_count;
        vector<int> v_temp = v;
        int pivot = i;

        //벡터 크기만큼 for 문을 돈다
        for (int j = 0; j < w * h; j++) {
            //기준 값보다 벡터에 저장된 값이 클 경우 같아질 때까지 블럭 수를 감소시킴
            if (v_temp[j] > pivot) {
                while (pivot != (v_temp[j])--) {
                    my_block++;
                    t += 2;
                }
                //기준 값보다 벡터에 저장된 값이 작을 경우 같아질 때까지 블럭 수를 증가시킴
            } else if (v_temp[j] < pivot) {
                while (pivot != (v_temp[j])++) {
                    my_block--;
                    t++;
                }
            }
        }

        //블럭 수가 음수가 아닐 경우
        if (my_block >= 0) {
            //final_h, final_t에 처음으로 값이 들어가는 경우 또는 구한 t가 final_t 보다 작을 경우 값을 업데이트함
            if ((final_h == 0 && final_t == 0) || (t < final_t)) {
                final_t = t;
                final_h = pivot;
            }
            //구한 t가 final_t와 같은 경우 높이가 더 높은 블럭으로 final_h 값을 업데이트함
            if (t == final_t){
                if(final_h < pivot){
                    final_t = t;
                    final_h = pivot;
                }
            }
        }
    }
    cout << final_t << " " << final_h;
}