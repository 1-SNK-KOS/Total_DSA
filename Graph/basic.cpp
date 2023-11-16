#include<bits/stdc++.h>
using namespace std;

int main()
{
int n,m;  // n->nodes m->egdes
cin>>n>>m;
// Graph here by matrix
int adj[n+1][m+1];
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;

    adj[u][v] = 1;
    adj[v][u] = 1;
}

// Graph here by List for undirected graph
// S.C O(2E)

// For Directed graph
// S.C O(E)
vector<int>adj[n+1];
for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;

    adj[u].push_back(v);  // for DG there will be u->v so only this line required
    // adj[v].push_back(u);
}
return 0 ;
}