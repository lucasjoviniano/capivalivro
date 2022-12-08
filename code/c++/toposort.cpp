// Retorna a ordenação em ordem inversa
void toposort(int u, const vector<vector<int>> &graph, vector<bool> &visited,
              vector<int> &order) {
  visited[u] = true;

  for (int j = 0, v; j < graph[u].size(); j++) {
    v = graph[u][j];
    if (!visited[v])
      toposort(u, graph, visited, order);
  }

  order.push_back(u);
}
