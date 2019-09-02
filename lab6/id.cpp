#include<bits/stdc++.h>
using namespace std;
int binarySearch(vector<pair<int,int>> &arr, int l, int r, int x) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
        if (arr[mid].first == x) 
            return mid; 
        if (arr[mid].first > x) 
            return binarySearch(arr, l, mid - 1, x); 
  
        return binarySearch(arr, mid + 1, r, x); 
    } 
  
    return -1; 
}

int main(){
    long long int n,q;cin>>n>>q;
    long long int maxid=-1,maxpaisa=INT_MIN;
    vector<pair<int,int>> queries;
    for(int i=0;i<q;i++){
        int x;cin>>x;
        if(x==1){
            int id,ps;cin>>id>>ps;
            pair <int,int> pi;
            pi.first=id;pi.second=ps;
            // pair<int,pair<int,int>> p;
            // p.first=1;
            // p.second=pi;
            queries.push_back(pi);
        }
        else if(x==2){
            
            pair <int,int> pi;
            pi.first=-1;pi.second=0;
            // pair<int,pair<int,int>> p;
            // p.first=2;
            //p.second=pi;
             queries.push_back(pi);
        }
        else{
            pair <int,int> pi;
            pi.first=-2;pi.second=0;
            // pair<int,pair<int,int>> p;
            // p.first=2;
            //p.second=pi;
             queries.push_back(pi);

        }

    }
    vector<int> id;
    for(int i=0;i<q;i++){
        if(queries[i].first>0){
            id.push_back(queries[i].first);
        }
    }
    vector <pair<int,int>> uniqueid;
    sort(id.begin(),id.end());
    int prev=0;
    for(int i=0;i<id.size();i++){
        if(id[i]!=prev){
            pair<int,int> p;
            p.first=id[i];
            p.second=0;
            uniqueid.push_back(p);
        }
        prev=id[i];
    }

    for(int i=0;i<q;i++){
       
        if(queries[i].first>0){
            int search=queries[i].first;
            int x=binarySearch(uniqueid, 0, uniqueid.size()-1,search);
            
            uniqueid[x].second+=queries[i].second;
            if(uniqueid[x].second>maxpaisa){
                maxpaisa=uniqueid[x].second;
                maxid=uniqueid[x].first;    
        }
        }
        else if(queries[i].first==-1){
            if(maxid==-1){
                cout<<"No data available.";
            }
            else{
                cout<<maxid;
            }
            cout<<endl;

        }
        else{
            cout<<"Invalid Input"<<endl;
        }
        
    }



}
