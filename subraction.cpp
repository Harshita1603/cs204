#include<bits/stdc++.h>
using namespace std;
string subract(string a ,string b){
	string ans;
	bool neg=0;
	//if b is greater than a, swap them
	if(a.length()<b.length()){
		swap(a,b);
		neg=1;
	}
	if(a.length()==b.length()){
		for(int i=0;i<a.length();i++){
			if(a[i]!=b[i]){
				if(a[i]<b[i]){
					swap(a,b);
				}
				break;
			}
		}
		neg=1;
	}
	//subract individual digits of a &b
	int carry=0;
	int nb= b.length(),na=a.length();
	int j=nb-1,i=na-1;
	while(j>=0){
		int s= a[i]-b[j]-carry;
		if(s<0){
			ans+=a[i]-b[j]+'0'+10-carry;
			carry=1;

		}
		else{
			ans+=a[i]-b[j]+'0'-carry;
			carry=0;
		}
		i--;j--;
	}
	//now push remaining integers of string a into the ans string
	while(i>=0){
		int s=a[i]-carry;
		if(s<0){
			ans+=(a[i]+10-carry);
			carry=1;
		}
		else{
			ans+=(a[i]-carry);
			carry=0;
		}
		i--;
	}
	int start=ans.size()-1;
	while(start>=0&&ans[start]=='0'){
		start--;
	}
	//now reverse them
	string res;
	for(int i=start;i>=0;i--)res+=ans[i];
    return res;



}
int main(){
	int t;cin>>t;
	while(t--){
	string a,b;
	cin>>a>>b;
	string ans =subract(a,b);
	cout<<ans<<endl;
}
	
}