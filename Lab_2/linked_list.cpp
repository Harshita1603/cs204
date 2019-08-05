#include<bits/stdc++.h>

using namespace std;

struct node{
	int x;int y;
	node *next;
	//Consructor
	node(int a,int b){
		x=a;
		y=b;
		next=NULL;
	}
};

struct linkedlist{
	node *head=NULL;
	void AddFirst(int a,int b){
		node *temp=new node(a,b);
		if(head==NULL){
			head=temp;
		}
		else{
			temp->next=head;
			head=temp;
		}
	}
	int DelFirst(){
		if(head==NULL){
			return -1;
		}
		node *temp=head;
		head=head->next;
		free(temp);
		return 0;
	}
	int Del(int a,int b){
		node *prev=NULL;
		node *present=head;
		while(present){
			if(present->x==a&&present->y==b){
				break;
			}
			prev=present;
			present=present->next;
		}
		if(present==NULL)return -1;
		if(present==head){
			
			return DelFirst();
		}
		prev->next=present->next;
		free(present);
	}
	void Search(float d){
		node *present=head;
		int count=0;
		while(present){
			if((present->x)*(present->x)+(present->y)*(present->y)<=d*d){
				cout<<"("<<(present->x)<<","<<(present->y)<<") ";
				count++;
			}
			present=present->next;
		}
		if(count==0){
			cout<<-1;
		}
		cout<<endl;
	}
	bool Search2(int a,int b){
		node *present=head;
		while(present){
			if(present->x==a&&present->y==b){
				return 1;
			}
			present=present->next;
		}
		return 0;
	}
	int length(){
		int count=0;
		node *present=head;
		while(present){
			count++;
			present=present->next;
		}
		return count;
	}
	void printll(){
		node *present=head;
		int count=0;
		while(present){
			
			cout<<"("<<(present->x)<<","<<(present->y)<<") ";
			present=present->next;
		}

	}


};

int main(){
	linkedlist l;
	unsigned long long int t;
	cin>>t;
	while(t--){
		int f;cin>>f;
		if(f==1){
			int a,b;
			cin>>a>>b;
			l.AddFirst(a,b);
		}
		if(f==2){
			l.DelFirst();
		}
		if(f==3){
			int a,b;
			cin>>a>>b;
			l.Del(a,b);
		}
		if(f==4){
			float d;
			cin>>d;
			l.Search(d);
		}
		if(f==5){
			int a,b;
			cin>>a>>b;
			if(l.Search2(a,b)){
				cout<<"True";
			}
			else{
				cout<<"False";
			}
			cout<<endl;
		}
		if(f==6){
			cout<<l.length()<<endl;
		}
		//l.printll();
	}

}
