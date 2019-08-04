#include<bits/stdc++.h>
using namespace std;

string add(string a, string b){
    int carry=0;
    string ans = "";
    if(a.size() < b.size()){
        swap(a,b);
    }
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    for(int i = 0; i< b.size(); i++){
        int sum = a[i]-'0'+b[i]-'0'+carry;
        ans+=sum%10+'0';
        carry=sum/10;
    }
    
    for(int i = b.size(); i<a.size(); i++){
        int sum = a[i]-'0'+carry;
        ans+=sum%10+'0';
        carry = sum/10;
    }
    if(carry){ans+= (carry+'0');}
    reverse(ans.begin(), ans.end());
    return ans;
}


int main(){
	int t;cin>>t;
	while(t--){
	string a,b;
	cin>>a>>b;
	string ans =add(a,b);
	cout<<ans<<endl;
}
	
}