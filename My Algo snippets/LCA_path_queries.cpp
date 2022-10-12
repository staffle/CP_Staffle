/*
    illustration of path XOR query in a tree without update.

*/
#include "bits/stdc++.h"
using namespace std;

#define ll long long

const int N = 1e5 + 10;

vector<vector<int>> g;
int dep[N], par[N][20], a[N], dis[N];

void dfs(int cv, int p) {
    dep[cv] = dep[p] + 1;
    par[cv][0] = p;
    dis[cv] = dis[p] ^ a[cv];
    for (auto i : g[cv]) {
        if (i != p) {
            dfs(i, cv);
        }
    }
}

int lca(int u, int v) {
    if (dep[u] > dep[v]) {
        swap(u, v);
    }
    for (int i = 19; i >= 0; i--) {
        if (dep[u] + (1 << i) <= dep[v]) {
            v = par[v][i];
        }
    }
    if (u == v) {
        return u;
    }
    for (int i = 19; i >= 0; i--) {
        if (par[u][i] == par[v][i]) {
            continue;
        }
        u = par[u][i];
        v = par[v][i];
    }
    return par[u][0];
}
void prep(int n) {
    par[1][0] = 1;
    for (int j = 1; j <= 19; ++j) {
        for (int i = 1; i <= n; ++i) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n, q;
    cin >> n >> q;
    g.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        g[i].clear();
    }

    for (int i = 1; i <= n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dis[0] = -1;
    dfs(1, 0);
    prep(n);

    while (q--) {
        int u, v;
        cin >> u >> v;
        int val = dis[u] ^ dis[v];
        val ^= a[lca(u, v)];
        cout << val << endl;
    }
    return 0;
}