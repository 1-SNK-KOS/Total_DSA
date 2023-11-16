#include<bits/stdc++.h>
/*
int bfs(vector<int>adj[],vector<int>&visited){
  int ans = -1;
     
  for(int i=1;i<visited.size();i++){
    
    if(visited[i] == 2){
        queue<int>q;
        q.push(i);

        while(!q.empty()){
            int size = q.size();
            ans++;
            for(int i=0;i<size;i++){
                int node = q.front();
                q.pop();


                for(auto it:adj[node]){
                    if(visited[it] == 1){
                        q.push(it);
                        // cout<<visited[it]<<it<<"1"<<endl;
                        visited[it] = -1;
                        // cout<<visited[it]<<it<<"2"<<endl;
                    }
                }
            }
        
        }
    }

  }
// for(int i=1;i<visited.size();i++){
//     cout<<visited[i]<<" ";
// }
for(int i=1;i<visited.size();i++){
   if(visited[i] == 1)return -1; 
}

if(ans == -1) return 0;
    return ans;
}
*/

int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
  vector<vector<int>>visited(n,vector<int>(m,0));
  queue<pair<pair<int,int>,int>>q;  // i,j ,time
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
              q.push({{i,j},0});
              visited[i][j] = 2;
            }
            if(grid[i][j] == 0){
                visited[i][j] = -1;
            }
        }
    }

// BFS
    int time = 0;
    while(!q.empty()){
   
      auto p = q.front();
      q.pop();
      
      int i=p.first.first;
      int j = p.first.second;
      time = p.second;
    //   visited[i][j] = 2;
      
      if(j+1<m && grid[i][j+1]==1 && !visited[i][j+1]){
            q.push({{i, j + 1}, time + 1});
            visited[i][j+1] = 2;
      }
      if(j-1>=0 && grid[i][j-1]==1 && !visited[i][j-1]){
            q.push({{i, j - 1}, time + 1});
            visited[i][j-1] = 2;
      } 
      if(i+1<n && grid[i+1][j]==1 && !visited[i+1][j]){
            q.push({{i+1, j}, time + 1});
            visited[i+1][j] = 2;
      } 
      if(i-1>=0 && grid[i-1][j]==1 && !visited[i-1][j]){
            q.push({{i-1, j }, time + 1});
            visited[i-1][j] = 2;
      }


    }
   for(int i=0;i<n;i++){
      for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0)
                return -1;
      }
   }

   return time;

    // Write your code here. 
   /* vector<int>visited(n*m+1);
    vector<int>adj[n*m+1];
    int twos = 0;
    int idx = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 0){
                visited[j+idx] = 0;
            }
            else if(grid[i][j] == 1){
                visited[j+idx] = 1;
                if(j+1<m && grid[i][j+1]==1)adj[j+idx].push_back(j+1+idx);
                if(i+1<n && grid[i+1][j]==1)adj[j+idx].push_back(j+(idx+m));
            }
            else{
             visited[idx+j] = 2;
             twos++;
             if(j+1<m && grid[i][j+1]==1)adj[j+idx].push_back(j+1+idx);
             if(i+1<n && grid[i+1][j]==1)adj[j+idx].push_back(j+(idx+m));
            }
        }
        idx+=m;
    }

  int ans = bfs(adj,visited);
  if (twos > 1 && ans != -1) {
        ans = floor(ans / 2);
        if(twos == ans) return 2;
  }
   return ans;
   */

}
}