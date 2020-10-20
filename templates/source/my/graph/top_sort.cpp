
template<typename T> vector<int> top_sort(const digraph<T>& g) {
  vector<int> deg(g.n);
  for (int i = 0; i < g.n; ++i) {
    for (auto id : g.g[i]) {
      if (g.edges[id].u == i) {
        ++deg[i];
      }
    }
  }
  queue<int> q;
  vector<int> res;
  res.reserve(g.n);
  for (int i = 0; i < g.n; ++i) {
    if (deg[i] == 0) {
      q.push(i);
    }        
  }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    res.push_back(v);
    for (auto id : g.g[v]) {
      if (g.edges[id].v == v) {
        int u = g.edges[id].u;
        if (--deg[u] == 0) {
          q.push(u);
        }
      }
    } 
  }
  return res;
}
