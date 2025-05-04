#include <bits/stdc++.h>
using namespace std;
void dfs(int i, vector<int> adj_list[], bool visited[]){
    visited[i] = true;

    cout << i << " ";
    for(int x: adj_list[i]){
        if(visited[x] == false){
            dfs(x, adj_list, visited);
        }
    }
}

int main()
{
    int i, j, u, v, nodes, edges;
    cin>>nodes>>edges;
    vector<int> adj_list[nodes + 1];
    bool visited[nodes+1];
    for(i = 0; i <= nodes; i++){
         visited[i] = false;
    }
    for(i = 1; i <= edges; i++){
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    dfs(1, adj_list, visited);
}