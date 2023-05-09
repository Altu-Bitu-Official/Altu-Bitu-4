#include <iostream>
#include<vector>
#include <stack> 
#include <queue>

using namespace std;

vector<bool> vistied_recur;

vector<int> dfs(int n,int v, vector<vector<bool>> edge)
{
    vector<int> result;
    vector<bool> visited(n+1,false);
    stack<int> s;

    s.push(v);
    visited[v]= true;
    result.push_back(v);

    while(!s.empty())
    {
        int node = s.top();
        bool child = false;

        for(int i=1; i<= n;i++)
        {
            if(edge[node][i]&& !visited[i])
            {
                child = true;
                s.push(i);
                visited[i]= true;
                result.push_back(i);
                break;
            }
        }
        if(!child)
        {
            s.pop();
        }
    }
    return result;
}

void dfsRecur(int n, int node, vector<vector<bool>> edge)
{
    vistied_recur[node] = true;
    cout << node << ' ';

    for(int i=1; i<= n;i++)
    {
        if(edge[node][i] && !vistied_recur[i])
        {
            dfsRecur(n,i,edge);
        }
    }
}

int main()
{
    int n,m,v, n1, n2;
    vector<vector<bool>> edge;

    cin >> n >> m >> v;
    edge.assign(n+1, vector<bool> (n+1, false));
    vistied_recur.assign(n+1, false);
    while(m--)
    {
        cin >> n1 >> n2;
        edge[n1][n2]= true;
        edge[n2][n1]= true;
    }

   // vector<int> dfs_result = dfs(n, v, edge);
    /*for(int i=0;i<dfs_result.size();i++)
    {
        cout << dfs_result[i]<< ' ';
    }*/
    
    dfsRecur(n, v, edge);
    cout << '\n';

}