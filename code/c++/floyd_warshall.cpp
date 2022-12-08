// Espera uma matriz de adjacência
void floyd_warshall(vector<vector<int>> &graph) {
  for (int k = 0; k < graph.size(); k++)
    for (int i = 0; i < graph.size(); i++)
      for (int j = 0; j < graph.size(); j++)
        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][i]);
}
