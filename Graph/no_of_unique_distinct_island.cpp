#include<bits/stdc++.h>
int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    // vector<vector<string>>store(n*m);  // i->level j->sum
    set<string>s;
    vector<vector<int>>visited(n,vector<int>(m,0));
    
//    char val[] = {'u','r','d','l'};
   int dx[] = {-1,0,1,0};
   int dy[] = {0,1,0,-1};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] && !visited[i][j]){
                visited[i][j] =1;
                
                // queue<pair<pair<int,int>,int>>q;
                queue<pair<int,int>>q;
                // q.push({{i,j},0});
                q.push({i,j});
                string value = "";
                // int level = 0;
                int base_i=i;
                int base_j=j;
                value+=to_string(0);
                value+=to_string(0);

                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    // level = q.front().second;
                    q.pop();
                    
                    for(int k=0;k<4;k++){
                        int nrow = r+dx[k];
                        int ncol = c+dy[k];
                        
                        while(nrow>=0 && ncol>=0 && nrow<n && ncol<m && arr[nrow][ncol] && !visited[nrow][ncol]){
                            q.push({nrow,ncol});
                            visited[nrow][ncol] = 1;
                            value+=to_string(nrow-base_i);
                            value+=to_string(ncol-base_j);
                           
                        }
                    }
                }
                if(s.find(value) == s.end()){
                    s.insert(value);
                }
                // bool checkisland = false;
                // for(auto it:store[level]){
                //     if(it == value){
                //         checkisland = true;
                //     }
                // }
                // if(!checkisland) store[level].push_back(value);   
                }
            }
        }
        int distinct = 0;
        // for(auto it:store){
        //     if(it.size()>0){
        //         distinct+=it.size();
        //     }
        // }
        distinct = s.size();
        return distinct;

    }


#include<bits/stdc++.h>
int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    // vector<vector<string>>store(n*m);  // i->level j->sum
    set<string>s;
    vector<vector<int>>visited(n,vector<int>(m,0));
    
//    char val[] = {'u','r','d','l'};
   int dx[] = {-1,0,1,0};
   int dy[] = {0,1,0,-1};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] && !visited[i][j]){
                visited[i][j] =1;
                
                // queue<pair<pair<int,int>,int>>q;
                queue<pair<int,int>>q;
                // q.push({{i,j},0});
                q.push({i,j});
                string value = "";
                // int level = 0;
                int base_i=i;
                int base_j=j;
                value+=to_string(0);
                value+=to_string(0);

                while(!q.empty()){
                    int r = q.front().first;
                    int c = q.front().second;
                    // level = q.front().second;
                    q.pop();
                    
                    for(int k=0;k<4;k++){
                        int nrow = r+dx[k];
                        int ncol = c+dy[k];
                        
                        while(nrow>=0 && ncol>=0 && nrow<n && ncol<m && arr[nrow][ncol] && !visited[nrow][ncol]){
                            q.push({nrow,ncol});
                            visited[nrow][ncol] = 1;
                            value+=to_string(nrow-base_i);
                            value+=to_string(ncol-base_j);
                           
                        }
                    }
                }
                if(s.find(value) == s.end()){
                    s.insert(value);
                }
                // bool checkisland = false;
                // for(auto it:store[level]){
                //     if(it == value){
                //         checkisland = true;
                //     }
                // }
                // if(!checkisland) store[level].push_back(value);   
                }
            }
        }
        int distinct = 0;
        // for(auto it:store){
        //     if(it.size()>0){
        //         distinct+=it.size();
        //     }
        // }
        distinct = s.size();
        return distinct;

    }


/*   
    Time Complexity = O(N * M)
    Space Complexity = O(N * M)
    
    where N and M are rows and columns 
    of the input array respectively
*/

#include <unordered_set>

int row[] = {0, -1, 0, 1};
int col[] = {-1, 0, 1, 0};
char sDir[] = {'l', 'u', 'r', 'd'};

string DFS(int** arr, int r, int c, string &s, char ch, int n, int m)
{
    //Marking island as visited
    arr[r][c] = 0;

    //Append the current state or direction for coding
    s += ch;

    //Search in 4 directions for 1s
    for (int i = 0; i < 4; i++)
    {
        int nr = r + row[i];
        int nc = c + col[i];

        //Make sure children are valid before traversing
        if (nr < 0 || nr >= n || nc < 0 || nc >= m || arr[nr][nc] == 0)
        {
            continue;
        }

        DFS(arr, nr, nc, s, sDir[i], n, m);
        s += 'b'; 
        
        // !!: Need to record the backtracking step.
        // So that, [[0, 1, 0], [0, 1, 0], [0, 1, 1]] and [[0, 1, 0], [0, 1, 1], [0, 1,
        // 0]] are different String
    }

    return s;
}

int distinctIslands(int **arr, int n, int m)
{
    unordered_set<string> islandSet;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 1)
            {

                // it will store the path of island
                string s = "";

                // add the path of DFS in set
                islandSet.insert(DFS(arr, i, j, s, 'S', n, m));
            }
        }
    }

    return islandSet.size();
}