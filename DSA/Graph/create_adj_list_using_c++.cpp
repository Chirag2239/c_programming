#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, u, v, nodes, edges;
    cin>>nodes>>edges;
    vector<int> adj_list[nodes + 1];
    for(i = 1; i <= edges; i++){
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    for(i = 1; i <= nodes; i++){
        cout<<"nodes adjacent to "<<i<<" are:";
        for(auto X: adj_list[i]){
            cout<< X << " ";
        }
        cout<<"\n";
    }
}