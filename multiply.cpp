#include<bits/stdc++.h>
using namespace std;

void multiply(string a,string b){
	vector <int> ans(a.length()+b.length(),0);
	int c1=0,c2=0;
	int nb= b.length(),na=a.length();
	
	int ai=0;
	for(int i=na-1;i>=0;i--){
		int carry=0;
		int bi=0;
		int num1 =a[i]-'0';
		for(int j=nb-1;j>=0;j--){
			int num2=b[j]-'0';
			int sum=num1*num2+carry+ans[ai+bi];
			carry=sum/10;
			ans[ai+bi]=sum%10;
			bi++;

		}
		if(carry>0){
			ans[ai+bi]+=carry;
		}
		ai++;
	}
	int start=ans.size()-1;
	while(start>=0&&ans[start]==0){
		start--;
	}
	for(int k=start;k>=0;k--){
		cout<<ans[k];
	}
	

}

int main(){
	int t;cin>>t;
	while(t--){
	string a,b;
	cin>>a>>b;
	multiply(a,b);
	cout<<endl;
	
}
	
}