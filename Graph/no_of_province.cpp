class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<int>visited(n+1);

        for(int i=1;i<=n;i++){
            if(!visited[i]){
              
               queue<int>q;
               q.push(i);
               visited[i] = 1;

               while(!q.empty()){
                   int node = q.front();
                   q.pop();

                   for(int j=0;j<n;j++){
                       if(isConnected[node-1][j]){
                       if(!visited[j+1]){
                           q.push(j+1);
                           visited[j+1] = 1;
                       }
                       }
                   }
               }

               ans++;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();

        vector<int> leads(n, 0);
        for (int i = 0; i < n; i++) { leads[i] = i; }   // initialize leads for every kid as themselves

        int groups = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {   // avoid recalculate M[i][j], M[j][i]
                if (M[i][j]) {
                    int lead1 = find(i, leads);
                    int lead2 = find(j, leads);
                    if (lead1 != lead2) {       // if 2 group belongs 2 different leads, merge 2 group to 1
                        leads[lead1] = lead2;
                        groups--;
                    }
                }
            }
        }
        return groups;
    }

private:
    int find(int x, vector<int>& parents) {
        return parents[x] == x ? x : find(parents[x], parents);
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        vector<bool> visited(n, false);
        int groups = 0;
        for (int i = 0; i < visited.size(); i++) {
            groups += !visited[i] ? dfs(i, M, visited), 1 : 0;
        }
        return groups;
    }

private:
    void dfs(int i, vector<vector<int>>& M, vector<bool>& visited) {
        visited[i] = true;
        for (int j = 0; j < visited.size(); j++) {
            if (i != j && M[i][j] && !visited[j]) {
                dfs(j, M, visited);
            }
        }
    }
};


// My code
int findNumOfProvinces(vector<vector<int>>& roads, int n) {
    // Write your code here.
    vector<int>visited(n+1,0);
    int ans = 0;
    bool check = false;
    for(int i = 1;i<=n;i++){
       for(int j = 1;j<=n;j++){
         if(roads[i-1][j-1]){
             if(!visited[i] && !visited[j]){
                 ans++;
                //  cout<<"1."<<ans<<endl;
                 check = true;
                 }
            else if(check && visited[j]){
                check = false;
                ans--;
                // cout<<"2."<<ans<<endl;
                }
             visited[i] = 1;
             visited[j] = 1;
             roads[i-1][j-1] = 0;
             roads[j-1][i-1] = 0;
         }
        //  check = false;
       }
       check = false;
    }
    for(int i=1;i<=n;i++){
        if(!visited[i])ans++;
    }
    return ans;
}


// more code
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        int n = isConnected.size();
        vector<int>visited(n+1);

        for(int i=1;i<=n;i++){
            if(!visited[i]){
              
               queue<int>q;
               q.push(i);
               visited[i] = 1;

               while(!q.empty()){
                   int node = q.front();
                   q.pop();

                   for(int j=0;j<n;j++){
                       if(isConnected[node-1][j]){
                       if(!visited[j+1]){
                           q.push(j+1);
                           visited[j+1] = 1;
                       }
                       }
                   }
               }

               ans++;
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();

        vector<int> leads(n, 0);
        for (int i = 0; i < n; i++) { leads[i] = i; }   // initialize leads for every kid as themselves

        int groups = n;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {   // avoid recalculate M[i][j], M[j][i]
                if (M[i][j]) {
                    int lead1 = find(i, leads);
                    int lead2 = find(j, leads);
                    if (lead1 != lead2) {       // if 2 group belongs 2 different leads, merge 2 group to 1
                        leads[lead1] = lead2;
                        groups--;
                    }
                }
            }
        }
        return groups;
    }

private:
    int find(int x, vector<int>& parents) {
        return parents[x] == x ? x : find(parents[x], parents);
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size();
        vector<bool> visited(n, false);
        int groups = 0;
        for (int i = 0; i < visited.size(); i++) {
            groups += !visited[i] ? dfs(i, M, visited), 1 : 0;
        }
        return groups;
    }

private:
    void dfs(int i, vector<vector<int>>& M, vector<bool>& visited) {
        visited[i] = true;
        for (int j = 0; j < visited.size(); j++) {
            if (i != j && M[i][j] && !visited[j]) {
                dfs(j, M, visited);
            }
        }
    }
};