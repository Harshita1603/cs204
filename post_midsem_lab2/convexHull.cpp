#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(a,b,c) for(lli a=b;a<c;a++)



struct point{
    lli x,y;
    
};
point x0;
point nexttostack(stack<point> s){
    point a= s.top();
    s.pop();
    point p=s.top();
    s.push(a);
    return p;
}

void swap(point &p1, point &p2){
    point t=p1;
    p1=p2;
    p2=t;
}

lli distancebwpoints(point p1,point p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
int orientation(point a,point b,point c){
    int x = (b.y-a.y)*(c.x-b.x) - (c.y-b.y)*(b.x-a.x);
    if(x==0){
        return 0;
    }
    if(x>0){
        return 1;
    }
    else{
        return 2;
    }
}

bool compare(point a,point b){
    int o=orientation(x0,a,b);
    if(o==0){
        if(distancebwpoints(x0,a)>=distancebwpoints(x0,b)){
            return 0;
        }
        else{
            return 1;
        }
    }
    if(o==1){
        return 1;
    }
    return 0;
}

void ConvexHull(vector <point> &arr,lli n){
    lli xmin = arr[0].x,min=0;
    for(lli i=1;i<n;i++){
        lli m = arr[i].x;
        if(xmin>m){
        	xmin=arr[i].x;
            min=i;
        }
        else if(xmin==m){
            if(arr[i].y<arr[min].y){
            	xmin=arr[i].x;
                min=i;
            }
        }
    }
    swap(arr[0],arr[min]);
    x0 = arr[0];
    auto it = arr.begin();
    it++;
    sort(it,arr.end(),compare);
    vector <point> nodup;
    nodup.push_back(x0);
    for(lli i=1;i<n;i++){
        while(i<n-1&&orientation(x0,arr[i],arr[i+1])==0){
            i++;
        }
        nodup.push_back(arr[i]);
    }
    if(nodup.size()<3){
        cout<<"NOT POSSIBLE"<<endl;
        return ;
    }
    stack<point> s;stack<point> sd;
    s.push(nodup[0]);s.push(nodup[1]);s.push(nodup[2]);
    for(lli i=3;i<nodup.size();i++){
        while(orientation(nexttostack(s),s.top(),nodup[i])!=1)s.pop();
        s.push(nodup[i]);
    }
    cout<<s.size()<<endl;
    while(!s.empty()){
        sd.push(s.top());
        s.pop();
    }
    while(!sd.empty()){
        cout<<sd.top().x<<" "<<sd.top().y<<endl;
        sd.pop();
    }

    
}



int main(){
    lli n;cin>>n;
    vector<point> v;
    for(lli i=0;i<n;i++){
        lli x,y;cin>>x>>y;
        point p;
        p.x=x;
        p.y=y;
        v.push_back(p);
    }
    ConvexHull(v,n);

}
