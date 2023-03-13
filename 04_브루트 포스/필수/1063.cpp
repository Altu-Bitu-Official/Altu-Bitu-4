#include <iostream>

using namespace std;


int main(){
    string k, s;
    char kx, sx; //킹과 돌의 x좌표
    char ky, sy; //킹과 돌의 y좌표
    int n;

    cin >> k >> s >> n;
    

    kx = k[0]; 
    sx = s[0];
    ky = k[1]; 
    sy = s[1];

    for(int i=0; i<n; i++){
        string dir;

        cin >> dir;
    
        if (dir == "R"){
            if((sx == kx + 1)&&(sy==ky)){
                if(sx=='H'){
                    continue;
                }
                sx++;
            }
            if(kx=='H'){
                continue;
            }
            kx++;
        }
        if (dir == "L"){
            if((sx == kx - 1)&&(sy==ky)){
                if(sx=='A'){
                    continue;
                }
                sx--;
            }
            if(kx=='A'){
                continue;
            }
            kx--;
        }
        if (dir == "B"){
            if((sy == ky - 1)&&(sx==kx)){
                if(sy=='1'){
                    continue;
                }
                sy--;
            }
            if(ky=='1'){
                continue;
            }
            ky--;
        }
        if (dir == "T"){
            if((sy == ky + 1)&&(sx==kx)){
                if(sy=='8'){
                    continue;
                }
                sy++;
            }
            if(ky=='8'){
                continue;
            }
            ky++;
        }
        if (dir == "RT"){
            if((sx  == kx + 1)&&(sy==ky+1)){
                if((sx=='H')||(sy=='8')){
                    continue;
                }
                sx++; sy++;
            }
            if((kx=='H')||(ky=='8')){
                continue;
            }
            kx++; ky++;
        }
        if (dir == "LT"){
            if((sx == kx - 1)&&(sy==ky+1)){
                if((sx=='A')||(sy=='8')){
                    continue;
                }
                sx--; sy++;
            }
            if((kx=='A')||(ky=='8')){
                continue;
            }
            kx--; ky++;
        }
        if (dir == "RB"){
            if((sx == kx + 1)&&(sy==ky-1)){
                if((sx=='H')||(sy=='1')){
                    continue;
                }
                sx++; sy--;
            }
            if((kx=='H')||(ky=='1')){
                continue;
            }
            kx++; ky--;
        }
        if (dir == "LB"){
            if((sx == kx - 1)&&(sy==ky-1)){
                if((sx=='A')||(sy=='1')){
                    continue;
                }
                sx--; sy--;
            }
            if((kx=='A')||(ky=='1')){
                continue;
            }
            kx--; ky--;
          }
    }

    cout << kx << ky << '\n';
    cout << sx << sy << '\n';


    return 0;
}