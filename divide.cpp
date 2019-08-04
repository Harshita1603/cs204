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
int Comparing2strings(string a,string b){
	int na=a.length(),nb=b.length();
	//cout<<a<<' '<<b<<endl;
	if(na<nb) return 1;
	if(na>nb) return -1;
	for(int i=0;i<na;i++){
		if(a[i]<b[i]) {
			return 1;}
		else if(a[i]>b[i]) { return -1;}
	}
	return 0;
}

void divide(string a ,string b){
	
	int nb= b.length(),na=a.length();
	if(Comparing2strings(a,b)==1){
		//cout<<"a";
		cout<<0<<endl<<a<<endl;
		return;
	}
	else if(Comparing2strings(a,b)==0){
		//cout<<"b";
		cout<<1<<endl<<0<<endl;
		return;
	}
	else{
		//cout<<"c";
		int k=b.size();
		vector<int> quotient;
		string remainder=a.substr(0,nb);
		int i=0;
		k--;
		while(k<a.size()){
			int count=0;
			while(Comparing2strings(b,remainder)==0||Comparing2strings(b,remainder)==1){
				remainder=subract(remainder,b);
				count++;
			}
			quotient.push_back(count);
			if(k==a.size()-1)
				break;
			remainder+=a[++k];
			i++;
		}
		int s=0;
		while(quotient[s]==0&&s<quotient.size())s++;

		for(int i=s;i<quotient.size();i++){
			cout<<quotient[i];

		}
		if(remainder.length()==0){
			remainder+="0";
		}
		cout<<endl<<remainder<<endl;

	}


}

int main(){
	int t;cin>>t;
	while(t--){
	string a,b;
	cin>>a>>b;
	divide(a,b);
	cout<<endl;
	
}
	
}