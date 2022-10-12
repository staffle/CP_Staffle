/*
    debugger explained
    step1 . copy paste those 3 lines into your template as it is. "No changes neccecery"
    they will not only make you debugger get working but also reduce compile time quite significantly.
    INVICTUS_123 {you might wanna remove above 2 lines and change every cerr in stdc++.h to cout}
*/
#define dbg(...) ; // remove this line if u can remember commenting every dbg() line before submitting (ps. i can not).
#define db(...) ; // // remove this line if u can remember commenting every dbg() line before submitting (ps. i can not).
#include "bits/stdc++.h"  // plz dont remove this ;)
// step2 . download the file stdc++.h from the link below and save it to path below.
/* 
    -link --> https://github.com/amit-nits/justforsharing/blob/master/debugger/stdc%2B%2B.h
    -path --> Current_program_path ( working folder )/ bits (Make the folder) / stdc++.h (filename)
*/
using namespace std;
const int MX = 1e3;
struct Enjoy_Example{
    Enjoy_Example(){
        db_example();
        dbg_example();
    }
    void db_example(){ // for an array or vector only .(workes for both single or multi dimention since it is recursive)
            int dp[MX][MX] = {0}; // gigantic global array can not print all of that to debug.
            int n= 6;
            
            /* no need to see code.*/
            dp[0][0] = 1;
            for(int i = 1;i <= n; i++)
                for(int j = 1; j <= n ; j++)
                    dp[i][j] = dp[i-1][j] + dp[i][j-1] + 2* dp[i-1][j-1];


//C d formet    db(nm ,d1s,d1e,d2s,d2e,d3s,....) d1s matlab dimention_1_start , d1e matlab end.
                db(dp , 1 , n , 1 , n);
        }
    void dbg_example(){
        // multiple argument deals with pretty much everything.
        int u , v , z;
        pair<int, pair<int, int>> p = {1 , {3,4}};
        pair<int, int> q = {1,3};
        vector<int> arr = {1,4,7,8,9};
        u = 8 , v = 9 , z = 12;
    // dbg(a1,b1,c1,d1,e1,....)
        dbg(u , v , q , p , arr); 
    }
} E;
int main(){
   ios::sync_with_stdio(0);cin.tie(0);cout.tie(0) ; cerr.tie(0);
}
// "bits/stdc++.h" credit - amit_dwivedi , tourist(to_string functions) , Um_nick (include files) , invictus_123(debugger)
