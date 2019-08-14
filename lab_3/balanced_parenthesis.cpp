#include<bits/stdc++.h>

using namespace std;

//function to check balanced parenthesis
bool balanced_parenthesis(string s){
	int n=s.length();
	stack <char> p;
	for(int i=0;i<n;i++){
		if(s[i]=='{'||s[i]=='['||s[i]=='('||s[i]=='<'){
			p.push(s[i]);
		}

		else if(s[i]=='}'){
			if(p.empty()==1){
				
				return 0;
				
			}
			else if(p.top()!='{'){
				
				return 0;
				
			}
			else p.pop();
		}
		else if(s[i]==']'){
			if(p.empty()==1){
				
				return 0;
				
			}
			else if(p.top()!='['){
				
				return 0;
				
			}
			else p.pop();
		}
		else if(s[i]=='>'){
			if(p.empty()==1){
				
				return 0;
				
			}
			else if(p.top()!='<'){
				
				return 0;
				
			}
			else p.pop();
		}
		else if(s[i]==')'){
			if(p.empty()==1){
				
				return 0;
				
			}

			else if(p.top()!='('){
				
				return 0;
				
			}
			else p.pop();
		}
		else if(s[i]=='|'){
			
			if(p.empty()!=1&&p.top()=='|')p.pop();
		
			else {p.push('|');}
		}
		else return 0;
		
	}

	if(p.empty()==1){
		
		return 1;
	}
	else return 0;

}


int main(){
	int q;cin>>q;
	for(int i=0;i<q;i++){
		string s;cin>>s;
	
		if(balanced_parenthesis(s))cout<<"YES";
		else cout<<"NO";
		cout<<endl;

	}
	return 0;
	

}
