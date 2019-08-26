#include<bits/stdc++.h>
using namespace std;
map <string,int> mp;
int val=0;
bool k=1;
int CodetheOperand(string m){
    //This function sets the precedence order of the operators
    if(m=="^")return 3;
    else if(m=="*"||m=="/")return 2;
    else if(m=="+"||m=="-")return 1;
    //in all other cases u need to return -1
    else return -1;
}
vector <string> ConvertinfixToPostfix(vector<string> exp) 
{ 
    stack<string> opwala;
    opwala.push("END"); 
    vector <string> opera; 
    for(int i = 0; i < exp.size(); i++) 
    { 
        
        if(exp[i]!="("&&exp[i]!=")"&&exp[i]!="*"&&exp[i]!="^"&&exp[i]!="-"&&exp[i]!="+"&&exp[i]!="/") 
        opera.push_back(exp[i]);
  
       
        else if(exp[i] == "(") 
          
        opwala.push("("); 
          
      
        else if(exp[i] == ")") 
        { 
            while(opwala.top() != "END"&& opwala.top() != "(") 
            { 
                string s = opwala.top(); 
                opwala.pop(); 
               opera.push_back(s);
            } 
            if(opwala.top() == "(") 
            { 
                string s = opwala.top(); 
                opwala.pop();  
            } 
        } 
          
        else{ 
            while(opwala.top() != "END" && CodetheOperand(exp[i]) <= CodetheOperand(opwala.top())) 
            { 
                if(CodetheOperand(exp[i])==3&&CodetheOperand(opwala.top())==3)break;
                string s = opwala.top(); 
                opwala.pop(); 
                opera.push_back(s); 
            } 
            opwala.push(exp[i]); 
        } 
  
    }
    while(opwala.top() != "END") 
    { 
        string s = opwala.top(); 
        opwala.pop(); 
        opera.push_back(s);
    } 
      
    return opera;
} 
struct  evalTree
{ 
    string value; 
    evalTree* left, *right; 
}; 
  
bool TheGivenIsaOperator(string s) 
{ 
    if (s == "+" || s== "-" || 
            s == "*" || s == "/" || 
            s == "^") 
        return 1; 
    else return 0; 
} 

pair <bool,int> assignment(vector<string> s){
    pair <bool,int> p;
    p.first=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=="="){
            p.first=1;
            p.second=i;
            break;
        }
    }
    return p;
}
evalTree* newNode(string val) 
{ 
    evalTree *temp = new evalTree; 
    temp->left = temp->right = NULL; 
    temp->value = val; 
    return temp; 
}; 
  
evalTree* constructTree(vector<string> pf) 
{ 
    stack<evalTree *> st; 
    evalTree *t, *t1, *t2; 
  
    
    for (int i=0; i<pf.size(); i++) 
    { 
       
        if (TheGivenIsaOperator(pf[i])==0) 
        { 
            t = newNode(pf[i]); 
            st.push(t); 
        } 
        else 
        { 
            t = newNode(pf[i]); 
  
           
            t1 = st.top(); 
            st.pop();      
            t2 = st.top(); 
            st.pop(); 
  
            
            t->right = t1; 
            t->left = t2; 
  
             
            st.push(t); 
        } 
    } 
  
    t = st.top(); 
    st.pop(); 
  
    return t; 
}
int StringtoInteger(string s)  
{  
    int num=stoi(s);
      
    return num;  
}
int evaluation(evalTree* head)  
{  
    
    if (!head)  
        return 0;  
  
    
    if (!head->left && !head->right) {
        string s=head->value;
        if((s[0]>='a'&&s[0]<='z')||(s[0]>='A'&&s[0]<='Z')){
                
                return mp.find(head->value)->second;
        }
        return StringtoInteger(head->value);  
    }
  
    
    int leftval = evaluation(head->left);  
   
    int rightval = evaluation(head->right);  
  
    
    if (head->value=="+")  
        return leftval+rightval;  
  
    if (head->value=="-")  
        return leftval-rightval;  
  
    if (head->value=="*")  
        return leftval*rightval;  
    if(head->value=="^"){
        return pow(leftval,rightval);
    }
  
    return leftval/rightval;  
}
bool isItaString(string s){
    if((s[0]>='a'&&s[0]<='z')||(s[0]>='A'&&s[0]<='Z')){
               
                return 1;
        }
    return 0;
}


vector <string> ConvertStringtovec(string s){
    vector <string> v;
    int op=0;
    int close=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]==')'||s[i]=='*'||s[i]=='^'||s[i]=='-'||s[i]=='+'||s[i]=='/'){
            
            string res;
            res+=s[i];
            if(i==0&&s[i]=='-'){
                close++;
                v.push_back("(");
                v.push_back("0");
                
            }
            
            if(i!=0&&(s[i]=='-'&&op==1)){
                close++;
                v.push_back("(");
                v.push_back("0");
            }
            
            if(s[i]!=')')op=1;
            v.push_back(res);
        }
        else if(s[i]=='='){
            string res;
            res+=s[i];
            v.push_back(res);
        }
        else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            string res;
            while(s[i]!='('&&s[i]!=')'&&s[i]!='*'&&s[i]!='^'&&s[i]!='-'&&s[i]!='+'&&s[i]!='/'&&i<s.length()){
                
                res+=s[i];
                i++;
            }
            i--;
            v.push_back(res);
        }
        else{
            op=0;
            string res;
            while(s[i]>='0'&&s[i]<='9'&&i<s.length()){
               
                res+=s[i];
                i++;
            }
            i--;
            v.push_back(res);
            while(close!=0){
                v.push_back(")");
                close--;
            }
        }
        
    }
    while(close!=0){
                v.push_back(")");
                close--;
            }
    return v;
}
int main(){
    unsigned long long int t;cin>>t;
    while(t--){
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
    bool equality=0;
    vector <string> v;
    int op=0;
    int close=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]==')'||s[i]=='*'||s[i]=='^'||s[i]=='-'||s[i]=='+'||s[i]=='/'){
            
            string res;
            res+=s[i];
            if(i==0&&s[i]=='-'){
                close++;
                v.push_back("(");
                v.push_back("0");
                
            }
            
            if(i!=0&&(s[i]=='-'&&op==1)){
                close++;
                v.push_back("(");
                v.push_back("0");
            }
            
            if(s[i]!=')')op=1;
            v.push_back(res);
        }
        else if(s[i]=='='){
            equality=1;
            op=1;
            string res;
            res+=s[i];
            v.push_back(res);
        }
        else if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z')){
            string res;
            while(((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))&&i<s.length()){
                
                res+=s[i];
                i++;
            }
            i--;

            v.push_back(res);
            while(close!=0){
                v.push_back(")");
                close--;
            }
        }
        else{
            op=0;
            string res;
            while(s[i]>='0'&&s[i]<='9'&&i<s.length()){
               
                res+=s[i];
                i++;
            }
            i--;
            v.push_back(res);
            while(close!=0){
                v.push_back(")");
                close--;
            }
        }
        
    }
    while(close!=0){
                v.push_back(")");
                close--;
            }
    bool flag=0;
    //cout<<equality<<"||";
    if(equality){
        vector <string> newvec;
        for(int i=2;i<v.size();i++){
            newvec.push_back(v[i]);
        }
        for(int i=0;i<newvec.size();i++){
            if(isItaString(newvec[i])){
                if(mp.find(newvec[i])==mp.end()){
                    cout<<"CANT BE EVALUATED"<<endl;
                    flag=1;
                }
            }
        }
        
        if(flag==0){
        vector <string> pf= ConvertinfixToPostfix(newvec);
        evalTree*t = constructTree(pf);
        int x=evaluation(t);
        
        if(mp.find(v[0])!=mp.end())mp.find(v[0])->second=x;
         else{
                pair<string,int> mypair;
                mypair.first=v[0];
                mypair.second=x;
                mp.insert(mypair);
            }
        }

    }
    else{   
        for(int i=0;i<v.size();i++){
            if(isItaString(v[i])){
                if(mp.find(v[i])==mp.end()){
                    cout<<"CANT BE EVALUATED"<<endl;
                    flag=1;
                }
            }
        }
            
        if(flag==0){   
            vector <string> o=ConvertinfixToPostfix(v);
            evalTree*t = constructTree(o);
            int x=evaluation(t);
           
            cout<<x<<endl;

        }
    }
    
    }
    
    mp.clear();
}
    
    return 0;
    
}
