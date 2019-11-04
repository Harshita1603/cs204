
#include<bits/stdc++.h>
using namespace std;




class UnionFind //rank is equal to number of vertices in a connected component
{
  public: vector<int> p, rank;
  // remember: vi is vector<int>
  UnionFind(int N) { for (int i = 0; i < N; i++) rank.push_back(1);
   for (int i = 0; i < N; i++) p.push_back(i); }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) 
  {
  if (!isSameSet(i, j)) {
  // if from different set
  int x = findSet(i), y = findSet(j);
  if (rank[x] > rank[y]) p[y] = x,rank[x]+=rank[y];
  // rank keeps the tree short
  else 
     {
     p[x] = y;
     rank[y]+=rank[x]; 
     }
  
  } 
 
  }   
};

int main(){
	vector<pair<long long int,pair<int,int>>> v;
	int n,e;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		
		int x,y;cin>>x>>y;
		long long int w;cin>>w;
		pair<int,int> c;
		c.first=x;c.second=y;
		pair<long long int,pair<int,int>> s;
		s.first=w;
		s.second=c;
		v.push_back(s);

	}
	sort(v.begin(),v.end());

	int count=0;
	long long int ans=1;
	UnionFind DSU(n-1);

	for(int i=e-1;i>=0;i--){
		if(!DSU.isSameSet(v[i].second.first,v[i].second.second)){
			DSU.unionSet(DSU.findSet(v[i].second.first),DSU.findSet(v[i].second.second));
			count++;
			ans*=((v[i].first%10000007)%10000007);
		}
		if(count==n-1)break;

	}
	cout<<ans<<endl;
}
