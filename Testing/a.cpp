#include "bits/stdc++.h"
using namespace std;using ll = long long;using ld = long double;
int v[20001];
void solve(){
    int n; cin>>n;
    for(int i=0; i<n; i++) {
        cin>>v[i];    
    }
    sort(v , v + n-1);
    for(int i=0; i<n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main() {
    // int _ = 0; cin>>_; while(_--)
    solve();
}
