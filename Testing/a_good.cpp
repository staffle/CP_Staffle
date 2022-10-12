#include <bits/stdc++.h>
using namespace std;using ll=long long;
int v[20001];
void solve(){
	int n; cin>>n;
    for(int i=0; i<n; i++) {
    	cin>>v[i];    
    }
    sort(v , v + n);
    for(int i=0; i<n; i++) {
    	cout << v[i] << " ";
    }
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);cerr.tie(0);
    // int _;cin>>_;while(_--)
    solve();
    return 0;
}