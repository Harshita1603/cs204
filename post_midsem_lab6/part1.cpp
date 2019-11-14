#include<bits/stdc++.h>

#define lli long long int
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define mp make_pair


using namespace std;

int main(){
    map<string,int> mp;
    vector<string> v;
    lli n;
    cin>>n;
    lli i;
    for(i=0;i<n;i++){
        string s,t; cin>>s;
        t=s; reverse(t.begin(),t.end());
        if(t!=s) {mp.insert({s,i});
        v.pb(t);}
    }
    for(i=0;i<v.size();i++){
        auto it = mp.find(v[i]);
        if(it!=mp.end()) {cout<<"YES\n"; return 0;}
    }
    cout<<"NO\n";
    return 0;

}
