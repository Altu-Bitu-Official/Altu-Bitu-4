// 킹

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
void moving(vector<string> s, int n, char king_x, int king_y, char rock_x, int rock_y){
    map<string, vector<int>> coord;
    coord["R"] = vector<int>{1,0};
    coord["L"] = vector<int>{-1,0};
    coord["B"] = vector<int>{0,-1};
    coord["T"] = vector<int>{0,1};
    coord["RT"] = vector<int>{1,1};
    coord["LT"] = vector<int>{-1,1};
    coord["RB"] = vector<int>{1,-1};
    coord["LB"] = vector<int>{-1,-1};
    
    for (int i=0; i<n; i++){
        king_x += coord[s[i]][0]; king_y += coord[s[i]][1];
        int rockmoved = 0;
        if (king_x == rock_x & king_y == rock_y){
            rock_x += coord[s[i]][0]; rock_y += coord[s[i]][1];
            rockmoved = 1;
        }
        if (min(king_x, rock_x) < 'A' || max(king_x, rock_x) > 'H' || min(king_y, rock_y)<1 || max(king_y, rock_y) > 8){
            king_x -= coord[s[i]][0]; king_y -= coord[s[i]][1];
            if (rockmoved == 1){
                rock_x -= coord[s[i]][0]; rock_y -= coord[s[i]][1];
            }
        }
    }
    cout << king_x << king_y << '\n' << rock_x << rock_y;
}

int main()
{   
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    char king_x, rock_x;
    string k;
    int king_y, rock_y, n;
    vector<string> s;
    
    cin >> king_x >> king_y >> rock_x >> rock_y >> n;
    for (int i=0; i<n; i++){
        cin >> k;
        s.push_back(k);
    }
    moving(s,n,king_x, king_y, rock_x, rock_y);
    return 0;
}