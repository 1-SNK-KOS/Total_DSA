vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.
    int visited[n]={0};
    vector<int>ans;
    queue<int>q;
    q.push(0);
    visited[0]=1;

    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    }

    return ans;
}