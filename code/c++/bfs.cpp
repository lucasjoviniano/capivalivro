void bfs(int v, const vector<vector<int>> &graph, vector<bool> &visited,
         vector<int> &d, vector<int> &p) {
  queue<int> q;

  q.push(v);
  visited[v] = true;
  p[v] = -1;

  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : graph[v]) {
      if (!visited[u]) {
        visited[u] = true;
        q.push(u);
        d[u] = d[v] + 1;
        p[u] = v;
      }
    }
  }
}

void retrieve_path(int u, const vector<bool> visited, const vector<int> &p) {
  if (!visited[u]) {
    cout << "No path!";
  } else {
    vector<int> path;
    for (int v = u; v != -1; v = p[v])
      path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int v : path)
      cout << v << " ";
  }
}
