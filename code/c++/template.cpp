#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define EPS 1e-9
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define mp make_pair
#define all(x) x.begin(), x.end()

template<typename A, typename B>
ostream &operator<<(ostream &s, const pair <A, B> &p) {
    return s << "(" << p.fi << ", " << p.se << ")";
}

template<typename T>
ostream &operator<<(ostream &s, const vector <T> &v) {
    s << "[";
    for (auto it: v) s << it << " ";
    s << "]";
    return s;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
}
