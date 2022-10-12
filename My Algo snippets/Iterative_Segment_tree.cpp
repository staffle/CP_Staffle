#include <bits/stdc++.h>
using namespace std;

/*
    seg tree RMQ with single element modification

    ==> Things to remember
    1. setting the value of n globally.
    2. complete the merge function.
    3. query works with 0 based indexing , [l , r) . r is exclused.
    4. set identity value, ID.  merge(a , ID) should be a.
    {
        for RMinQ : ID = INF
            RMaxQ : ID = -INF
        Xor,RSumQ : ID = 0
          Product : ID = 1
    }
    5. set type of value in each node T (int , long long or special type of node);

*/

const int N = 1e5 + 10;
const int ID = 1e9;
struct node {
    int val;
    node(int a_) {
        val = a_;
    }
    node() {
        val = ID;
    }
};
using T = node;

T t[2 * N + 100];

int n;

T merge(T a, T b) {
    return min(a.val, b.val);
}

void build() {
    for (int i = n - 1; i > 0; i--)
        t[i] = merge(t[i << 1], t[(i << 1) + 1]);
}

// gives merge element from [l,r) p.s. r exclusive
int query(int l, int r) {
    T res = ID;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (r & 1)
            res = merge(res, t[--r]);
        if (l & 1)
            res = merge(res, t[l++]);
    }
    return res.val;
}
void modify(int p, long new_val) // update new_val at position p
{
    p += n;
    t[p] = new_val;
    for (; p > 1; p /= 2) {
        t[p / 2] = merge(t[p], t[p ^ 1]);
    }
}

int main() {
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; ++i)
        cin >> t[i + n].val;
    build();
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << query(l, r + 1) << endl;
    }
    return 0;
}
// i think, the same implementation will work for range sum, range max and
//    all commutative properties. just a few changes
