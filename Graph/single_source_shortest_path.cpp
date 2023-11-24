// Brute Force
#include <bits/stdc++.h>
vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {
    // Write your code here.
    vector<int>adj[n];

  // Storage
    for(auto i:edges){
        adj[i[0]].push_back(i[1]);
        adj[i[1]].push_back(i[0]);
        }
    

// Vis for track
    vector<int>vis(n,0);
// for answer
   vector<int>ans(n,-1);

// BFS
   queue<pair<int,int>>q;
   q.push({src, 0});
   vis[src] = 1;
   
  while(!q.empty()){
    int node = q.front().first;
    int len = q.front().second;
    ans[node] = len;
    q.pop();

  for(auto it:adj[node]){
      if(!vis[it]){
        q.push({it, len + 1});
        vis[it] = 1;  
      }
  }

 
  }
return ans;
}


// DFS
/*
    Time Complexity : O(N*(N+M))
    Space Complexity : O( N )

    Where 'N' is the number of nodes and 'M' is the total edges in the graph.
*/

void DFS(int node, int dest, vector<int>adjacencyList[], vector<bool>&visited, int &minimumLength, int currentLength) {
	// If 'node' equals 'dest':
	if (node == dest) {
		minimumLength = min(minimumLength, currentLength);
		return;
	}

	visited[node] = true;

	// For each unvisited adjacent node 'u' to 'node'.
	for (auto u : adjacencyList[node]) {
		if (visited[u] == false) {
			DFS(u, dest, adjacencyList, visited, minimumLength, currentLength + 1);
		}
	}

	visited[node] = false;
}

vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {

	// Initialize an ‘answer’ array of length ‘N’ with 0.
	vector<int>answer(n, 0);

	// Iterate over the edges and create the ‘adjacencyList’ for the graph.
	vector<int>adjacencyList[n];
	for (auto edge : edges) {
		int u = edge[0], v = edge[1];
		adjacencyList[u].push_back(v);
		adjacencyList[v].push_back(u);
	}

	// Do a DFS.
	for (int node = 0; node < n; node++) {

		// Initialize an integer variable ‘minimumLength’ with a
		// large integer value and ‘currentLength’ with 0.
		int minimumLength = INT_MAX, currentLength = 0;

		vector<bool>visited(n, false);

		DFS(node, src, adjacencyList, visited, minimumLength, currentLength);

		answer[node] = minimumLength;
	}

	// For each value of 'answer' array, update infinity with -1.
	for (int i = 0; i < n; i++) {
		if (answer[i] == INT_MAX) {
			answer[i] = -1;
		}
	}

	// Return array 'distance'.
	return answer;
}

// DIjkstra
/*
    Time Complexity : O(M*log(N))
    Space Complexity : O( N )

    Where 'N' is the number of nodes and 'M' is the total edges in the graph.
*/

vector<int> shortestPath(int n, vector<vector<int>>&edges, int src) {

	// Iterate over the edges and create the 'adjacencyList' for the graph.
	vector<int>adjacencyList[n];
	for (auto edge : edges) {
		int u = edge[0], v = edge[1];
		adjacencyList[u].push_back(v);
		adjacencyList[v].push_back(u);
	}

	// Initialize an array 'distance' of size 'N' (number of vertices) and
	// set all values to infinity except 'distance[src]' = 0.
	vector<int>distance(n, INT_MAX);
	distance[src] = 0;

	// Create a priority queue 'pq' to store visited vertices.
	// Enqueue a pair(vertices, cost) with vertex as source and cost as 0 into 'pq'.
	priority_queue<pair<int, int>>pq;
	pq.push({src, 0});

	while (pq.size()) {
		pair<int, int>current = pq.top();
		pq.pop();
		int u = current.first, cost = current.second;

		// If 'cost' > 'distance[u]', continue to the next iteration.
		if (cost > distance[u]) {
			continue;
		}

		for (auto v : adjacencyList[u]) {
			int newCost = cost + 1;
			if (newCost < distance[v]) {
				distance[v] = newCost;
				pq.push({v, newCost});
			}
		}
	}

	// For each value of 'distance' array, update infinity with -1.
	for (int i = 0; i < n; i++) {
		if (distance[i] == INT_MAX) {
			distance[i] = -1;
		}
	}

	// Return array 'distance'.
	return distance;

}