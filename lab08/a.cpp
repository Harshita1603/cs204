#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(a,b,c) for(lli a=b;a<c;a++)


void swap(lli *a,lli *b){
    lli t=*a;
    *a=*b;
    *b=t;
}
lli part(lli *arr,lli l,lli r,lli x){
    lli i;
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
  
    i = l; 
    for (lli j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i;
}

lli HowToFindMedian(lli *a,lli n){
    sort(a,a+n);
    return a[(n)/2];
}

lli ktSmallest(lli *arr, lli l, lli r, lli k) 
{ 
     
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; 
  
        
        lli i;
        lli median[(n+4)/5];
        for (i=0; i<n/5; i++) 
            median[i]=(HowToFindMedian(arr+(l+i*5), 5)); 
        if (i*5 < n) 
        { 
            median[i]=(HowToFindMedian(arr+(l+i*5), n%5));  
            i++; 
        }     
  
        lli medOfMed = (i == 1)? median[i-1]: 
                                 ktSmallest(median, 0, i-1, i/2); 
  
      
        lli pos = part(arr, l, r, medOfMed); 
  
       
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  
            return ktSmallest(arr, l, pos-1, k); 
  
       
        return ktSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
    return INT_MAX; 
} 



int main(){
    lli t;cin>>t;
    while(t--){
        lli n;cin>>n;
        lli v[n];
        for(lli i=0;i<n;i++){
            lli x,y;
            cin>>x>>y;
            long long int d= x*x + y*y;
            v[i]=d;
        }
        unsigned long long int d= ktSmallest(v,0,n-1,(n)/2);
        cout<<pow(d,0.5)<<endl;
    }


}
