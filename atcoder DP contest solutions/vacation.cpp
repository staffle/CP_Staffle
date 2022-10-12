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
vector<vector<ll>> a(mx,vector<ll>(3,-1));
vector<vector<ll>> dp(mx,vector<ll>(3,-1));
ll mp[][2] = {{1,2},{0,2},{0,1}};
ll foo(int src, int choice=-1){
    if(choice==-1){ // can make any choice
        return dp[src][choice] = max({foo(src,0),foo(src,1),foo(src,2)});
    }
    if(dp[src][choice]!=-1)
        return dp[src][choice];
    if(src==n-1){
        return dp[src][choice] = a[src][choice];
    }

    else{
        ll ans_ = max(foo(src+1,mp[choice][0]),foo(src+1,mp[choice][1])) + a[src][choice];
        return  dp[src][choice] =  ans_;
    }


    

}
void solve(){
    cin>>n;
    for (int i = 0; i < n; ++i)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    ll ans = -1;
    for(auto i : {0,1,2}){
        for (int j = 0; j < n; ++j)
        {
            dp[j][i] = -1;
        }
        ans = max(ans , foo(0,i));  
    }
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
