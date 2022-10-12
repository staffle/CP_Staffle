#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
#ifdef LOCAL
#include "1.h"
#else
#define dbg(...) 
#endif
ll n,m,i,j,k,in,cnt = 0,l,r,u,v,x,y,tc = 1,mod = 1000000007 , ans , inf = 1e18;
const ll  mx = 100001 ;
vector<ll> a(mx,0), b(mx,0);
vector<vector<ll>> dp(mx,vector<ll>(101,-1));
ll foo(int weight , int pos){
    // dbg(weight , pos);
    if(weight == 0 or pos==n)
        return 0;
    if(dp[weight][pos]!=-1)
        return dp[weight][pos];
    else{
        ll ans1 = 0;
        // dbg(weight , pos);
        if(a[pos] <= weight)
            ans1 =  max(b[pos] + foo(weight-a[pos], pos+1), ans1);
        ans1 = max(ans1 , foo(weight , pos+1));
        // dbg(weight , pos , ans1);
        return dp[weight][pos] = ans1;
    }
        
}
void solve(){
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i]>>b[i];
    }
    ll ans = -1;
    ans = foo(m,0);
    cout << ans << endl;
    
}
signed main(){                                          //F
    clock_t time = clock();                             //A
    ios_base::sync_with_stdio(0);                       //S
    cin.tie(0);                                         //T
    cout.tie(0);                                        //I
    cerr.tie(0);                                        //O
    if(0) cin>>tc;
    while(tc--)
        solve();
    dbg("Author - Amit dwivedi");
    return 0&fprintf(stderr, "Time ::%.3lf ms.\n",((clock() - time)*1000.0)/CLOCKS_PER_SEC);
}
