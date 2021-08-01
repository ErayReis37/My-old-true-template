template<typename T> struct fenwick {
  int n;
  vector<T> tree;
  fenwick(int _n, T def = T{}) : n(_n) {
    tree.resize(n + 1);
    tree[0] = def;
  }

  void modify(int i, T x) {
    assert(i >= 0 && i < n);
    ++i;
    while (i <= n) {
      tree[i] += x;
      i += (i & -i);
    }
  }

  T get(int i) {
    assert(i >= 0 && i < n);
    ++i;
    T res = tree[0];
    while (i > 0) {
      res += tree[i];
      i -= (i & -i);
    }
    return res;
  }

  T get(int l, int r) {
    return get(r) - (l == 0 ? tree[0] : get(l - 1));
  }

  template<class F> int find_first(F op) {
    int cur = 0;
    T sum = tree[0];
    for (int i = __lg(n); i >= 0; --i) {
      if (cur + (1 << i) <= n && !op(sum + tree[cur + (1 << i)])) {
        cur += (1 << i);
        sum = sum + tree[cur]; 
      }      
    }
    return (cur == n ? -1 : cur);
  }
  
  void clear() {
    tree.assign(n + 1, tree[0]);
  }
};
