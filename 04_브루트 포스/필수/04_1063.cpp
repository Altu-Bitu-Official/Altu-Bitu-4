#include <iostream>
#include <string>
#include <vector>//pair를 사용

using namespace std;
typedef pair<char, char> cc;//좌표를 저장할 pair 선언

cc move(string input, char x, char y){//이동함수 x:열, y:행
    for(int i=0; i<input.size(); i++){//input의 크기가 문자 하나 or 둘이기 때문
        char how = input[i]; //앞에서부터 문자 하나씩 판단하여 연산
        if(how == 'R'){//방향이 R일때
            x++; //x축 방향으로 한칸 더함
        }
        else if(how == 'L'){//방향이 L일때
            x--; //x축 방향으로 한칸 뺌
        }
        else if(how == 'B'){//방향이 B일때
            y--; //y축 방향으로 한칸 뺌
        }
        else {//T
            y++; //y축 방향으로 한칸 더함
        }
    }
    return {x,y}; //연산 이후의 x,y 좌표를 반환함
}

bool checkRange(cc position){//범위를 체크하는 함수
    if(position.first < '1' || position.second > '8'){//위치가 체스보드 밖으로 나가는 경우
        return false;//false 반환
    }
    return true;//체스보드 범위 안에 있을 경우 true를 반환
}

bool isSame(cc k, cc s){//king stone 위치가 같을 경우
    return (k.first == s.first && k.second == s.second); //k,s 의 x,y 좌표는 동일함을 반환
}

int main(){//메인함수
    cc k,s; //king, stone의 pair 선언
    int n; //몇 번 움직이는지
    string input; //움직이는 방향의 문자열

    cin >> k.first >> k.second >> s.first >> s.second >> n;//입력받기

    while(n--){//n만큼 반복한다
        cin >> input;//문자열 입력

        cc next_k, next_s; //이동 후 위치 저정할 변수

        next_k = move(input, k.first, k.second); //king 이동

        if(isSame(next_k,s)){//king stone 위치 같을 때
            next_s = move(input, s.first, s.second); //stone 이동
        }
        else{//위치가 다르다면
            next_s = s;//stone은 위치를 유지한다
        }
        
        //범위 체크
        if(checkRange(next_k) && checkRange(next_s)){//king stone이 체스보드 밖으로 나가는지 체크
            k = next_k;//king의 좌표
            s = next_s;//stone의 좌표
        }
        
    }
    cout << k.first << k.second << "\n" << s.first << s.second;//출력


    return 0;//끝
}