struct DSU	// ~ amit_dwivedi
{
	vector<int> parent,size;
	DSU(int n){
		parent.resize(n+1);
		size.resize(n+1);
		for (int i = 1; i <= n; ++i)
		{
			parent[i] = i;
			size[i] = 1;
		}
	}
	int set_size(int a)
	{
		return size[find(a)];
	}
	int find(int v)
	{
		return v==parent[v] ? v: find(parent[v]);
	}
	void merge(int a,int b)
	{
		a = find(a);
		b = find(b);
		if(a!=b)
		{
			if(size[a]<size[b])
			{
				swap(a,b);
			}
			parent[b] = a;
			size[a]+=size[b];
		}
	}
	bool same(int a,int b)
	{
		if(find(a)==find(b)) return 1;
		return 0;
	}
};
