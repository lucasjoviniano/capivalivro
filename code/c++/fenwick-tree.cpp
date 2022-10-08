const int neutral = 0;
#define comp(a, b) ((a)+(b))

// ATENÇÃO: Indexa do 1
class FenwickTree {
private:
    vector<int> ft;
public:
    FenwickTree(int n) {
        ft.assign(n + 1, 0);
    }

    int rsq(int i) { // Retorna RSQ(1, i)
        int sum = neutral;
        for (; i; i -= (i & -i)) sum = comp(sum, ft[i]);
        return sum;
    }

    int rsq(int i, int j) {
        return rsq(j) - rsq(i - 1);
    }

    void update(int i, int v) {
        for (; i < (int)ft.size(); i += (i & -i))
            ft[i] = comp(v, ft[i]);
    }
};
