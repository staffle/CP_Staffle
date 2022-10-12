#include "bits/stdc++.h"
using namespace std;using ll=long long;
const ll inf = 1e18;
const int mx = 1e5;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd(ll x=0, ll y=inf) {return (rng() % (y-x +1)) + x;};
namespace generator{
	ll get_num(ll a = 0 , ll b = inf){
		return rnd(a,b);
	}
	string get_string(int len = -1,bool lowercase_only = true){
		if(len==-1){
			len = rnd(1,mx);
		}
		string s(len,'0');
		for(int i = 0; i < len; i++)
			s[i] = (rnd(0,25) + 'a');
		if(lowercase_only) return s;
		for(auto&i:s){
			if(rng()&1) i^=32; // swap case (make c to C)
		}
		return s;
	}
	template<typename T>
	vector<T> get_array(int len = -1 , T a = 0,T b = inf){
		if(len==-1){
			len = rnd(1,mx);
		}
		vector<T> s(len);
		for(int i = 0; i < len; i++)
			s[i] = (rnd(a,b));
		return s;
	}
	vector<pair<int, int>> get_tree(int n = -1){
		if(n==-1) n = rnd(1,mx);
		vector<pair<int, int>> res(n-1);
		for(int i = 2; i <= n; i++){
			int u = i , v = rnd(1 , i-1);
			if(rng()&1) swap(u,v);
			res[i-2] = {u,v};
		}
		shuffle(res.begin() , res.end() , rng);
		return res;
	}
	vector<pair<int, int>> get_simple_graph(int n , int m , bool connected = true){
		vector<pair<int, int>> res;
		set<pair<int , int>> edge_set;
		assert(2*m <= 1ll*n*(n-1)); // maximum condition for edge
		if(connected){
			assert(m >= n-1); // minimum edges of connected graph
			res = get_tree(n);
			for(auto i:res) edge_set.insert(i);
			res.clear();
			for(int i = n; i <= m; i++){
				label:
				int u = rnd(1,n);
				int v = rnd(1,n);
				if(u==v or edge_set.count({u,v}) or edge_set.count({v,u})) goto label;
				else{
					edge_set.insert({u,v});
				}
			}

		}
		else{
			for (int i = 1; i <= m; ++i)
			{
				label2:
				int u = rnd(1,n);
				int v = rnd(1,n);
				if(u==v or edge_set.count({u,v}) or edge_set.count({v,u})) goto label2;
				else{
					edge_set.insert({u,v});
				}
			}
		}
		for(auto i:edge_set){
			res.push_back(i);
		}
		shuffle(res.begin() , res.end() , rng);
		return res;
	}
};
using namespace generator;
/*
	-> get_num (a , b); // gives a random number between [a,b] if a , b given. otherwise get_num() gives a random_number between 0 and 10**18;
	-> get_string(l , bool lowercase_only = true) gives a string of length , (by default lowercase you can change that by calling get_string(len,false)); 
	-> get_array(len , min_num_of_array , max_num_of_array) note that this returns a vector;
	-> get_tree(n) gives a tree of n nodes (list of edges)
	-> get_simple_graph(nodes, edges , bool  connected = 1) // you can change connected/disconnected option too. (list of edges)
*/
struct demo{
	demo(){
		cout << get_num() << endl;
		cout << get_num(10 , 20) << "\n";
		vector<int> v = get_array(12 , 1 , 1000); // size , min_element , max_element.
		// you can call g.get_array() , or g.get_array(10) too , see definition for details.
		cout << "the array generated is {";
		for(auto i: v)
			cout << i << ", ";
		cout << " }" << endl;

		vector<pair<int, int>> tree = get_tree(5);
		cout << "the tree generated has edgelist { ";
		for(auto i: tree)
			cout << "(" << i.first << ", " << i.second << ") , ";
		cout << " }" << endl;

		// similary for graph
		get_simple_graph(10 , 12); // connected_graph
		get_simple_graph(10 , 12 , 0); // can be disconnected_graph
		// both graph will have 10 nodes and 12 edges.
	}

};


/* for a question having sample tests like this
T 
N
S (an string)
an array of size N.(a1 , a2 , a3 , a4 , .... an)
*/
void example(){
	int N = get_num(1,10);
	string s = get_string(N);
	vector<int> v = get_array(N , 0 , 20);
	// you have to output them too.
	cout << N << endl;
	cout << s << endl;
	for(auto i:v) cout << i << " "; cout << endl;
}
/*-----------------------------------------------------------------------------------------------------------*/
// comment/uncomment the next line in if you have test_cases.
#define SINGLE_TEST
const int max_tests = 1;
// complete this function for each test case.
void make_test(){





}
int main(){
    // demo* d = new demo;
    int t = 1;
    #ifndef SINGLE_TEST 
    	t = get_num(1,max_tests), cout << t << endl;
    #endif
    while(t--){
    	make_test();
    	// example();
    }
    
}
