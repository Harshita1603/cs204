#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(a,b,c) for(lli a=b;a<c;a++)


void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int part(int *arr,int l,int r,int x){
    int i;
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
  
    i = l; 
    for (int j = l; j <= r - 1; j++) 
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

int HowToFindMedian(int *a,int n){
    sort(a,a+n);
    return a[(n)/2];
}

int ktSmallest(int *arr, int l, int r, int k) 
{ 
     
    if (k > 0 && k <= r - l + 1) 
    { 
        int n = r-l+1; 
  
        
        int i, median[(n+4)/5]; 
        for (i=0; i<n/5; i++) 
            median[i] = HowToFindMedian(arr+l+i*5, 5); 
        if (i*5 < n) 
        { 
            median[i] = HowToFindMedian(arr+l+i*5, n%5);  
            i++; 
        }     
  
        int medOfMed = (i == 1)? median[i-1]: 
                                 ktSmallest(median, 0, i-1, i/2); 
  
      
        int pos = part(arr, l, r, medOfMed); 
  
       
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  
            return ktSmallest(arr, l, pos-1, k); 
  
       
        return ktSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
    return INT_MAX; 
} 



int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int a[1000000];
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            unsigned long long int d= x*x + y*y;
            a[i]=d;
        }
        unsigned long long int d= ktSmallest(a,0,n-1,(n)/2);
        cout<<pow(d,0.5)<<endl;
    }


}
