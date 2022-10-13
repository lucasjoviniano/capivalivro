class KMP {
  string p;
  vector<int> v;
  int m;

public:
  KMP(const char *_p) : p(_p) {
    m = p.size();
    v.assign(m + 1, -1);
    for (int i = 0, j = -1; i < m;) {
      while (j >= 0 && p[i] != p[j])
        j = v[j];
      v[++i] = ++j;
    }
  }

  vector<int> match(const char* t) {
    vector<int> ans;

    for (int i = 0, j = 0, n = strlen(t); i < n;) {
      while (j >= 0 && t[i] != p[j])
        j = v[j];
      i++;
      j++;
      if (j == m) {
        ans.push_back(i - j);
        j = v[j];
      }
    }

    return ans;
  }
};
