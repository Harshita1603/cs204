#include<bits/stdc++.h>
using namespace std;

string add(string a,string b){
	//if b has more digits than a,swap them
	if(a.length()<b.length()){
		swap(a,b);
	}
	string ans;
	int carry=0;
	int nb= b.length(),na=a.length();
	int j=nb-1,i=na-1;
	//add individual digits of a &b 
	while(j>=0){
		ans+=((a[i]+b[j]-2*'0'+carry)%10+'0');
		carry=(a[i]+b[j]-2*'0'+carry)/10;
		i--;j--;
	}
	//now push remaining integers of string a into the ans string 
	while(i>=0){
		ans+=((a[i]-'0'+carry)%10+'0');
		carry=(a[i]-'0'+carry)/10;
		i--;
	}
	//now reverse them
	string res;
	for(int i=ans.length()-1;i>=0;i--)res+=ans[i];
    return res;
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