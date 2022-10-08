const int neutral = 0;
#define comp(a, b) ((a)+(b))

class SegmentTree {
    vector<int> a;
    int n;
public:
    SegmentTree(int *st, int *en) {
        int sz = int(en - st);

        for (n = 1; n < sz; n <<= 1);
        a.assign(n << 1, neutral);
        for (int i = 0; i < sz; i++) a[i + n] = st[i];
        for (int i = n + sz - 1; i > 1; i--) {
            a[i >> 1] = comp(a[i >> 1], a[i]);
        }
    }

    void update(int i, int x) {
        a[i += n] = x;
        for (i >>= 1; i; i >>= 1) {
            a[i] = comp(a[i << 1], a[1 + (i << 1)]);
        }
    }

    int query(int l, int r) {
        int ans = neutral;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ans = comp(ans, a[l++]);
            if (r & 1) ans = comp(ans, a[--r]);
        }
        return ans;
    }
};
