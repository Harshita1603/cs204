#include<iostream>
using namespace std;
template <typename T>
struct node{
    T data;
    node * next;
    node(T data){
        this->data= data;
        next = NULL;
    }
};
template <typename Y>
struct stack{
    node<Y> * head;
    int count;
    stack(){
        head = NULL;
        count = 0;
    }
    bool isEmpty(){
        return head==NULL;
    }
    int size(){
        return count;
    }
    void push(Y data){
        node<Y> * temp = new node<Y>(data);
        count++;
        /*if(!head){
            head = temp;
            return;
        }*/
        temp->next = head;
        head = temp;
        return;
    }
    void pop(){
        if(!isEmpty()){
            node<Y> * temp =  head;
            head = head->next;
            count--;
            delete temp;
        }
        return;
    }
    Y top(){
        if(!isEmpty()){
            return head->data;
        }
        return -1;
    }
};
int main(){
    string br;
	cin>>br;
	stack <int> s;
	for(int i=0;i<br.length();++i)
	{
		if(br[i]=='(')
		{
			s.push(1);
		}
		else if(br[i]==')')
		{
			if(s.isEmpty())
				{cout<<"Invalid"<<endl;return 0;}
			if(s.top()==1){s.pop();}
		}
		else
			{cout<<"Random Character entered"<<endl;return 0;}
	}
	if(s.isEmpty())
		{cout<<"Valid"<<endl;}
	else 
		cout<<"Invalid"<<endl;
	return 0;
}
