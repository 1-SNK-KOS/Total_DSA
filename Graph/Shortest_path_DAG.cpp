// Brute DFS
void dfs( vector<pair<int,int>>adj[],vector<int>&ans,vector<int>&pathvis,vector<int>&vis,int node,int pathsum ){
    vis[node] = 1;
    pathvis[node] = 1;

    for(auto it:adj[node]){
     if(!vis[it.first]){
         // Sum to save
         if(ans[it.first] == -1) ans[it.first] = pathsum+it.second;
         else ans[it.first] = min(ans[it.first],pathsum+it.second);
          // funt calling
         dfs(adj,ans,pathvis,vis,it.first,pathsum+it.second);
     }
     else if(!pathvis[it.first]){
         // Sum to save
         if(ans[it.first] == -1) ans[it.first] = pathsum+it.second;
         else ans[it.first] = min(ans[it.first],pathsum+it.second);
          // funct calling
         dfs(adj,ans,pathvis,vis,it.first,pathsum+it.second);
     }
    }

    pathvis[node] = 0;
}


vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Write your code here
    vector<pair<int,int>>adj[n];  // storage -> a->index , {b,weight}

    for(auto i:edges){
        adj[i[0]].push_back({i[1],i[2]});
    }
     
    vector<int>vis(n,0);
    vector<int>pathvis(n,0);

    vector<int>ans(n,-1);
     ans[0] = 0;
    dfs(adj,ans,pathvis,vis,0,0);


    return ans;
}

//Dijkstra
/*
    Time Complexity: O(N+M*log(N))
    Space Complexity: O(N+M)

    where 'N' and 'M' are the number of vertices and the number of edges, respectively.
*/

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Creating an adjacency list 'adj' using given edges, which stores {destination, weight}.
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    // Initializing a priority queue 'pq', which stores the distance of any vertex with 0 and that vertex.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Initializing array 'dis' of size 'N' with 10^9.
    vector<int> dis(n, 1e9);
    dis[0] = 0;
    pq.push({dis[0], 0});

    // Finding shortest distances.
    while (pq.size() > 0)
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        for (auto i : adj[u])
        {
            int v = i.first;
            int w = i.second;
            if (dis[v] > dis[u] + w)
            {
                // Updating dis[v].
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }

    // If 'dis[i]' is 10^9 for some vertex 'i', then assigning -1 in 'dis[i]'.
    for (int i = 0; i < n; i++)
    {
        if (dis[i] == 1e9)
        {
            dis[i] = -1;
        }
    }
    return dis;
}

// Topo SOrt
/*
    Time Complexity: O(N+M)
    Space Complexity: O(N)

    where 'N' and 'M' are the number of vertices and the number of edges, respectively.
*/

void dfs(int i, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st)
{
    vis[i] = 1;
    for (auto j : adj[i])
    {
        if (vis[j.first] == 0)
        {
            dfs(j.first, adj, vis, st);
        }
    }
    st.push(i);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    // Creating an adjacency list 'adj' using given edges, which stores {destination, weight}.
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
    }

    // Initializing empty stack 'st'.
    stack<int> st;

    // Finding topological sort.
    vector<int> vis(n);
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i, adj, vis, st);
        }
    }

    // Initializing array 'dis' of size 'N' with 10^9.
    vector<int> dis(n, 1e9);
    dis[0] = 0;

    // Finding shortest distances.
    while (st.size() > 0)
    {
        int u = st.top();
        st.pop();

        for (auto i : adj[u])
        {
            int v = i.first;
            int w = i.second;
            if (dis[v] > dis[u] + w)
            {
                // Updating dis[v].
                dis[v] = dis[u] + w;
            }
        }
    }

    // If 'dis[i]' is 10^9 for some vertex 'i', then assigning -1 in 'dis[i]'.
    for (int i = 0; i < n; i++)
    {
        if (dis[i] == 1e9)
        {
            dis[i] = -1;
        }
    }
    return dis;
}