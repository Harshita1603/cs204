#include<iostream>
#include<vector>
using namespace std;

struct stack{
    vector <int> v;
    int size(){
        return v.size();
    }
    bool isEmpty(){
        return v.size()==0;
    }
    void push(int data){
        v.push_back(data);
        return;
    }
    void pop(){
        if(!isEmpty()){
            v.pop_back();
        }
        return;
    }
    int top(){
        if(!isEmpty()){
            return v[v.size()-1];
        }
        return -1;
    }
};
int main(){
    
}
