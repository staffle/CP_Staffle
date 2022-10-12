// a generic trie implementation base on problem 
// https://www.codechef.com/problems/MCO16304
// fluffy and typing passwords
struct trie{
	struct node{
		int data,flag;
		unordered_map<char,node*> m;
		node(){
			data=INT_MAX;
			flag=0;
		}
	};
	node* root = new node; // the root of the trie

	void insert(string &s){
		node* cur=root;
		int n=s.length();
		cur->data=min(cur->data,n);
		fr(i,0,n){
			char c=s[i];
			if(!cur->m.count(c)){
				cur->m[c]=new node;
			}
			cur=cur->m[c];
			cur->data=min(cur->data,n-i-1);
		}
	}
	int query(string &s){
		int ans=INT_MAX;
		node* cur=root;
		int n=s.length();
		ans=min(ans,n+cur->data);
		fr(i,0,n){
			char c=s[i];
			if(!cur->m.count(c)){
				return ans;
			}
			cur=cur->m[c];
			ans=min(ans,cur->data+n-i-1);
		}
		return min(ans,cur->data);
	}
} t;
