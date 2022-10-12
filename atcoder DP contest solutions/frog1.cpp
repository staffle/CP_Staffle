#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
#ifdef LOCAL
#include "1.h"
#else
#define dbg(...) 
#endif
ll n,m,i,j,k,in,cnt = 0,l,r,u,v,x,y,tc = 1,mod = 1000000007  ;
const ll  mx = 100001 ;
vector<ll> a(mx);
vector<int> dp(mx,-1);
ll foo(int src){
    if(dp[src]!=-1)
        return dp[src];
    if(src==n-1){
        return 0;
    }
    else{
        ll ans  = abs(a[src]- a[src+1]) + foo(src+1);
        if(src+2 < n)
            ans = min(ans,abs(a[src]- a[src+2]) + foo(src+2));
        return dp[src]=ans;
    }
}
void solve(){
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }
    cout<<foo(0)<<endl;
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
