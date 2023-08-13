struct LCA {
  int n, LOG;
  vector<vector<int>> g;
  vector<vector<int>> up;
  vector<int> dep;
  
  LCA(int n_) {
    n = n_;
    LOG = 63 - __builtin_clzll(n);
    g.resize(n, {});
    up.resize(n, vector<int>(LOG));
    dep.resize(n);
  }
  
  void add_edge(int a, int b) {
    g[a].push_back(b);
    g[b].push_back(a);
  }
  
  void build(int v, int p) {
    for (int j = 1; j < LOG; j++) {
      up[v][j] = up[up[v][j - 1]][j - 1];
    }
    for (auto u : g[v]) {
      if (u != p) {
        dep[u] = dep[v] + 1;
        up[u][0] = v;
        build(u, v);
      }
    }
  }
  
  int jump(int v, int k) {
    for (int j = LOG - 1; j >= 0; j--) {
      if (k >> j & 1) {
        v = up[v][j];
      }
    }
    return v;
  }
  
  int lca(int a, int b) {
    if (dep[a] < dep[b]) swap(a, b);
    a = jump(a, dep[a] - dep[b]);
    
    if (a == b) return a;
    
    for (int j = LOG - 1; j >= 0; j--) {
      if (up[a][j] != up[b][j]) {
        a = up[a][j];
        b = up[b][j];
      }
    }
    return up[a][0];
  }
  
  int dist(int a, int b) {
    return dep[a] + dep[b] - 2 * dep[lca(a, b)];
  }
};
