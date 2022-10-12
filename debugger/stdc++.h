#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <queue>
#include <iomanip>
#include <bitset>
#include <stack>
#include <iterator>
#include <complex>
#include <climits>
using namespace std;

#define n_l '\n'




 template <typename T, size_t N>
 int SIZE(const T (&t)[N]){
     return N;
 }

 template<typename T>
 int SIZE(const T &t){
     return t.size();
 }

 string to_string(const string s, int x1=0, int x2=1e9){
     return '"' + ((x1 < s.size()) ? s.substr(x1, x2-x1+1) : "") + '"';
 }

 string to_string(const char* s) {
     return to_string((string) s);
 }

 string to_string(const bool b) {
     return (b ? "true" : "false");
 }

 string to_string(const char c){
     return string({c});
 }

 template<size_t N>
 string to_string(const bitset<N> &b, int x1=0, int x2=1e9){
     string t = "";
     for(int __iii__ = min(x1,SIZE(b)),  __jjj__ = min(x2, SIZE(b)-1); __iii__ <= __jjj__; ++__iii__){
       t += b[__iii__] + '0';
     }
     return '"' + t + '"';
 }

 template <typename A, typename... C>
 string to_string(const A (&v), int x1 = 0, int x2=1e9, C... coords);

 int l_v_l_v_l = 0, t_a_b_s = 0;

 template <typename A, typename B>
 string to_string(const pair<A, B> &p) {
     l_v_l_v_l++;
     string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
     l_v_l_v_l--;
     return res;
 }

 template <typename A, typename... C>
 string to_string(const A (&v), int x1, int x2, C... coords) {

     int rnk = rank<A>::value;
     string tab(t_a_b_s, '   ');

     string res = "";
     bool first = true;

     if(l_v_l_v_l == 0) res += n_l;
     res += tab + "{";

     x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v));
     auto l = begin(v);
     advance(l, x1);
     auto r = l;
     advance(r, (x2-x1) + (x2 < SIZE(v)));

     for (auto e = l; e != r; e = next(e)) {
         if (!first) {
             res += ", ";
         }
         first = false;

         l_v_l_v_l++;
         if(e != l){
             if(rnk > 1) {
                 res += n_l;
                 t_a_b_s = l_v_l_v_l;
             };
         }
         else{
             t_a_b_s = 0;
         }

         res += to_string(*e, coords...);
         l_v_l_v_l--;
     }
     res += "}";
     if(l_v_l_v_l == 0) res += n_l;
     return res;
 }

void err(istream_iterator<string> it) {
    cerr << endl;
}

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << to_string(a) << "| ";
	err(++it, args...);
}
 
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define db(args...)  cerr << "[" << #args << "] = "; cerr << to_string(args)
#define dbgl(...) cerr << "line " << __LINE__ << ": "; dbg(__VA_ARGS__)
#define assrt(c) if(!(c)) {throw runtime_error(string() + #c + " Condition not satisfied in line " + to_string(__LINE__) + " in " + __PRETTY_FUNCTION__);}
#define ONLINE_JUDGE 0
