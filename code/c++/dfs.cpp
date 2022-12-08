void dfs(int v, const vector<vector<int>> &graph, vector<bool> &visited) {
  visited[v] = true;
  for (int u : graph[v]) {
    if (!visited[u])
      dfs(u, graph, visited);
  }
}
