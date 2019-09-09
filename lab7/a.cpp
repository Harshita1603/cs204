#include<bits/stdc++.h>
using namespace std;

bool Appending2strings(string a,string b){
    string ans1,ans2;
    ans1=a.append(b);
    ans2=b.append(a);
    if(ans1>ans2)return 1;
    else return 0;    
}

string makeBohotBadaNumber(vector <string> mystrings){
    string ans;
    sort(mystrings.begin(),mystrings.end(),Appending2strings);
    int i=0;
    while(i<mystrings.size()){
        ans+=mystrings[i];
        i++;
    }
    return ans;

}

int main(){

    int t;
    cin>>t;
    while(t--){
        vector<string> v;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            v.push_back(s);
        }
        string ans=makeBohotBadaNumber(v);
        cout<<ans<<endl;


    }

    

}
