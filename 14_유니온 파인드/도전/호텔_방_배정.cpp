#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
typedef long long ll;

unordered_map <ll, ll> parent;

//Find 연산
ll findParent(ll node) {
    if (parent[node] == 0) { // 방이 비어 있는 경우 즉시 배정
        parent[node] = node + 1; // 방이 배정되었으므로 다음 방으로 업데이트
        return node;
    }
    return parent[node] = findParent(parent[node]);
}

vector<ll> assignRoom(vector<ll>& room_number) {
    vector<ll> answer;
    for (ll num : room_number) {
        ll room = findParent(num); // 방 배정
        answer.push_back(room);
    }
    return answer;
}

vector<ll> solution(ll k, vector<ll> room_number) {
    vector<ll> answer = assignRoom(room_number);
    return answer;
}

/*
 * 투숙객이 원하는 방이 비어 있다면 방 배정
 * 방 배정 후, 해당 방의 다음 방을 집합의 루트 정점으로 설정 (다음 빈 방을 바로 찾을 수 있음)
 * 벡터로 parent를 선언하면 전체 방 개수(k)의 최대가 10^12이기 때문에 메모리 초과
 * 필요한 방의 parent 정보 저장을 위해 map 사용 (key: 방 번호, value: 문제의 조건 4를 만족하는 방의 번호)
 * 그냥 map 사용시 시간초과, 키 값을 정렬하지 않는 unordered_map 사용
 */

int main() {
    ll k = 10;
    vector<ll> room_number = { 1, 3, 4, 1, 3, 1 };
    vector<ll> result = solution(k, room_number);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << ' ';
    }
    return 0;
}