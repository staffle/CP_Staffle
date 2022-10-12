template <class T>
struct SparseTable {
    ll n;
    vector<vector<T>> mat;
 
    T func(const T& a, const T& b) const {
        return __gcd(a, b);
    }
 
    SparseTable(const vector<T>& a) {
        n = static_cast<ll>(a.size());
        ll max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (ll j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (ll i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
 
    T get(ll from, ll to) const {
        ll lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};
