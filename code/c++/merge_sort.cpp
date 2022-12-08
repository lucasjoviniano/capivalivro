#include <bits/stdc++.h>
using namespace std;

template <typename T> ostream &operator<<(ostream &s, const vector<T> &v) {
  s << "[";
  for (auto it : v)
    s << it << " ";
  s << "]";
  return s;
}

void merge(vector<int> &v, int l, int m, int r) {

  int i, j, k;

  vector<int> a(m - l + 1);
  vector<int> b(r - m);

  for (i = 0; i < a.size(); i++)
    a[i] = v[l + i];
  for (j = 0; j < b.size(); j++)
    b[j] = v[m + 1 + j];

  i = 0;
  j = 0;
  k = l;

  while (i < a.size() || j < b.size()) {
    if (j >= b.size() || (i < a.size() && a[i] <= b[j])) {
      v[k] = a[i];
      i++;
    } else {
      v[k] = b[j];
      j++;
    }
    k++;
  }
}

void merge_sort(vector<int> &v, int l, int r) {
  if (l < r) {
    int m = l + (r - 1) / 2;
    merge_sort(v, l, m);
    merge_sort(v, m + 1, r);
    merge(v, l, m, r);
  }
}

int main() {
  vector<int> v{3, 5, 9, 1, 2, 6};
  vector<int> u(v);
  sort(u.begin(), u.end());
  merge_sort(v, 0, v.size() - 1);
  cout << v << endl;
  cout << u << endl;
}
