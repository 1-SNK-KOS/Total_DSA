void dfs(vector<int>&temp,int start,vector<int>&visited,vector<int> adj[]){
  /*  if(visited[start]) return ;
    visited[start] = 1;
    temp.push_back(start);

    for(auto it:edges){
        if((it[0] == start  && !visited[it[1]])){
            dfs(temp,it[1],visited,edges);
        }
        else if((it[1] == start && !visited[it[0]])){
            dfs(temp,it[0],visited,edges);
        }
    }
    */
      if(!visited[start]){
           visited[start] = 1;
           temp.push_back(start);
        }
        for(auto it:adj[start]){
            if(!visited[it]){
                dfs(temp,it,visited,adj);
            }
        }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // Write your code here
    // cout<<edges.size()<<edges[0].size()<<endl;;
  vector<vector<int>>ans;
  vector<int>visited(V,0);

  vector<int>adj[V];
  for(auto it:edges){
      adj[it[0]].push_back(it[1]);
      adj[it[1]].push_back(it[0]);
  }

  for(int i=0;i<V;i++){
      if(!visited[i]){
          vector<int>temp;
          dfs(temp,i,visited,adj);
          ans.push_back(temp);
      }
  }
  
  return ans;
}