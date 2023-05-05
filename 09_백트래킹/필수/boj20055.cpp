#include<iostream>
#include <deque>

using namespace std;

deque<int> durability;
deque<bool> exist;

void move(int n) {
    //컨베이어 벨트 이동
    durability.push_front(durability.back());//뒤에 있는거 앞으로 이동
    durability.pop_back();//뒤에 있는거 삭제
    exist.push_front(exist.back());
    exist.pop_back();
    exist[n - 1] = false;
    int num = 0;
    //로봇이동
    for (int i = n - 2; i >= 0; i--) {
        if (exist[i] && !exist[i + 1] && durability[i + 1] > 0) {
            exist[i] = false;
            exist[i + 1] = true;
            durability[i + 1]--;

        }
    }
    //벨트이동 동시에 로봇 끝에 있었다면 내림
    exist[n - 1] = false;
}

bool check(int n, int k) {
    int zero_cnt = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (durability[i] == 0) {
            zero_cnt++;
        }
    }
    if (zero_cnt >= k) {
        return true;
    }
    return false;
}


int main() {
    int ans = 1;
    int n, k;
    int A;
    cin >> n >> k;
    //컨베이어 벨트설정
    for (int i = 0; i < 2 * n; i++) {
        cin >> A;
        durability.push_back(A);
        exist.push_back(false);
    }
    //exist[0] = true;
    //durability[0]--;
    int zero_cnt = 0;
    while (true) {
        //로봇&컨베이어 이동
        move(n);
        //로봇 올려놓는다
        if (exist[0] == false && durability[0] > 0) {
            exist[0] = true;
            durability[0]--;
            if (durability[0] == 0) {
                zero_cnt++;
            }
        }
        //durability = 0 인 칸 갯수가 k 이상이면 끝
        if (check(n, k)) {
            cout << ans;
            break;
        }
        ans++;
    }
}