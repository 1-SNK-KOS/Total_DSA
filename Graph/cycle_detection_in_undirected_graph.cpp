/*
    Time Complexity : O(M * log(N))
    Space Complexity : O(N)

    where 'N' is the number of vertices and
    'M' is the number of edges in the graph.
*/

int findparent (int i, vector<int>& parent)
{
    if (i == parent[i])
    {
        return i;
    }
    return parent[i] = findparent (parent[i], parent);
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    vector<int> parent(n + 1, 0);
    vector<int> rank(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        rank[i] = 1;
        parent[i] = i;
    }

    for (vector<int>& ar : edges)
    {
        int u = ar[0];
        int v = ar[1];

        int p1 = findparent (u, parent);
        int p2 = findparent (v, parent);

        if (p1 != p2)
        {
            if (rank[p1] < rank[p2])
            {
                parent[p1] = p2;
            }
            else if (rank[p1] > rank[p1])
            {
                parent[p2] = p1;
            }
            else
            {
                parent[p1] = p2;
                rank[p2]++;
            }
        }
        else
        {
            return "Yes";
        }
    }
    
    return "No";
}

#include<bits/stdc++.h>
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
     if(m == 0)return "No";

    // Write your code here.
    vector<int>adj[n+1];
    vector<pair<int,int>>visited(n+1,{0,0});
    for(int i=0;i<edges.size();i++){
        int p1 = min(edges[i][0],edges[i][1]);
        int p2 = max(edges[i][1],edges[i][0]);
        adj[p1].push_back(p2);
        adj[p2].push_back(p1);
    }

   for(int i=1;i<visited.size();i++){
       if(!visited[i].first && adj[i].size()!=0){
          queue<int>q;
          q.push(i);
  
          visited[i]={1,0};
          int parent = i;
          while(!q.empty()){
              int node = q.front();
              q.pop();
             if(visited[node].second)  parent = node;
            

              for(auto it:adj[node]){
                  if(!visited[it].first){
                      q.push(it);
                      visited[it] = {1,parent};
                  }
                  else if (visited[node].second!=it) {
                      return "Yes";
                  }
              }
          }

       }
   }


return "No";
}

