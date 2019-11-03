//Print the numbers in the given Range
#include<iostream>
#include<queue>
using namespace std;
struct node {
    int data;
    node * left;
    node * right;
    node(int data){
        this->data = data;
        left = right = NULL;
    }
};
void addElement(node *& root,int data){
    if(!root){
        root = new node(data);
        return;
    }
    node * it = root;
    node  * prev = NULL;
    while(it){
        if(it->data < data){
            prev = it;
            it = it->right;
        }else{
            prev = it;
            it = it->left;
        }
    }
    if(prev->data > data){
        prev->left = new node(data);
    }else{
        prev->right = new node(data);
    }
    return;
}
bool search(node * root,int data){
    if(!root){
        return false;
    }
    if(root->data==data){
        return true;
    }
    if(root->data > data){
        return search(root->left,data);
    }else{
        return search(root->right,data);
    }
}
node * deleteElement(node * root,int data){
    if(!root){
        return NULL;
    }
    if(root->data == data){
        // no child
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }
        // 1 child
        if((!root->left && root->right) || (root->left && !root->right)){
            node * temp;
            if(root->left){
                temp = root->left;
            }else{
                temp = root->right;
            }
            delete root;
            return temp;
        }
        // 2 child
        node * parent = root;
        node * it = root->left;
        while(it->right){
            parent = it;
            it = it->right;
        }
        if(parent!=root){
            parent->right = it->left;
            it->left = root->left;
        }
        it->right = root->right;
        delete root;
        return it;
    }

    if(root->data > data){
        root->left = deleteElement(root->left,data);
    }else{
        root->right = deleteElement(root->right,data);
    }
    return root;
}
int minValue(node * root){
    while(root->left){
        root = root->left;
    }
    return root->data;
}
void printAtDiffLevel(node * root){
    queue<node *>q1;
    queue<node *>q2;
    q1.push(root);
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            node * top = q1.front();
            cout<<top->data<<" ";
            q1.pop();
            if(top->left){
                q2.push(top->left);
            }
            if(top->right){
                q2.push(top->right);
            }
        }
        cout<<endl;
        while(!q2.empty()){
            node * top = q2.front();
            cout<<top->data<<" ";
            q2.pop();
            if(top->left){
                q1.push(top->left);
            }
            if(top->right){
                q1.push(top->right);
            }
        }
        cout<<endl;
    }
}

void preorder(node * root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    return;
}
void inorder(node * root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    return;
}
void postorder(node * root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    return;
}
void printInRange(node * root,int k1,int k2){
    if(!root){
        return;
    }
    if(root->data >= k1){
        printInRange(root->left,k1,k2);
    }
    if(root->data >= k1 && root->data<=k2){
        cout<<root->data<<" ";
    }
   if(root->data < k2){
        printInRange(root->right,k1,k2);
   }
}


int main(){
   int n;cin>>n;
   node *root=NULL;
   for(int i=0;i<n;i++){
    int x;cin>>x;
    addElement(root,x);
   }

   cout<<"Inorder Traversal :";
   cout<<endl;
   inorder(root);
   cout<<endl;
   int k1,k2;cin>>k1>>k2;
   cout<<"The numbers present in the BST in the range ("<<k1<<" , "<<k2<<") are : "<<endl;
   printInRange(root,k1,k2);

}
