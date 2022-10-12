#include "bits/stdc++.h"
using namespace std;

using ll = long long;
/*
    Lazy seg tree that support
    = range update and range queries
    = (point update and point queries too.)
    ==> Things to remember
    1. complete the merge and push function.
    2. query works with 0 based indexing , [l , r]
    3. set identity value, ID in strct node.
*/

struct lazyseg {

#define lc cur + cur + 1
#define rc cur + cur + 2
#define mid (s + e) / 2

    struct node {
        ll val = 0; // 0 for sum query
        ll lazy = -1;
    };

    ll n;
    vector<node> seg;

    node merge(const node &a, const node &b) {
        node res;
        res.val = a.val + b.val;
        return res;
    }

    inline void push(ll cur, ll s, ll e) {
        if (seg[cur].lazy == -1)
            return;
        if (s != e) {
            seg[lc].lazy += seg[cur].lazy;
            seg[rc].lazy += seg[cur].lazy;
        }
        seg[cur].val += (e - s + 1) * seg[cur].lazy;
        // seg[cur].val += seg[cur].lazy;
        seg[cur].lazy = -1;
    }

    void pull(ll cur) {
        seg[cur] = merge(seg[lc], seg[rc]);
    }

    void build(ll cur, ll s, ll e) {
        if (s == e) {
            seg[cur].val = 0;
            return;
        }
        build(lc, s, mid);
        build(rc, mid + 1, e);
        pull(cur);
    }

    template <class M> void build(ll cur, ll s, ll e, const vector<M> &v) {
        if (s == e) {
            seg[cur].val = v[s];
            return;
        }
        build(lc, s, mid, v);
        build(rc, mid + 1, e, v);
        pull(cur);
    }

    template <class M> void update(ll cur, ll s, ll e, ll l, ll r, const M &v) {
        push(cur, s, e);
        if (s > r || e < l)
            return;
        if (l <= s && e <= r) {
            seg[cur].lazy += v;
            push(cur, s, e);
            return;
        }
        update(lc, s, mid, l, r, v);
        update(rc, mid + 1, e, l, r, v);
        pull(cur);
    }

    node query(ll cur, ll s, ll e, ll l, ll r) {
        push(cur, s, e);
        if (s > r || e < l)
            return node();
        if (l <= s && e <= r)
            return seg[cur];
        return merge(query(lc, s, mid, l, r), query(rc, mid + 1, e, l, r));
    }

#undef lc
#undef rc
#undef mid

    lazyseg(ll _n) : n(_n) {
        assert(n > 0);
        seg.resize(4 * n);
        build(0, 0, n - 1);
    }

    template <class M> lazyseg(const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        seg.resize(4 * n);
        build(0, 0, n - 1, v);
    }

    template <class M> void update(ll idx, const M &val) {
        if (idx < 0 || idx > n - 1)
            return;
        update(0, 0, n - 1, idx, idx, val);
    }

    template <class M> void update(ll l, ll r, const M &val) {
        if (l < 0 || l > n - 1 || r < 0 || r > n - 1 || r < l)
            return;
        update(0, 0, n - 1, l, r, val);
    }

    node query(ll l, ll r) {
        if (l < 0 || l > n - 1 || r < 0 || r > n - 1 || r < l)
            return node();
        return query(0, 0, n - 1, l, r);
    }
    node query(ll idx) {
        if (idx < 0 || idx > n - 1)
            return node();
        return query(0, 0, n - 1, idx, idx);
    }
};

//

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    lazyseg seg(a);

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        cout << seg.query(l).val << endl;
    }
    return 0;
}