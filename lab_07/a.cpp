#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define f(a,b,c) for(lli a=b;a<c;a++)


void swap(unsigned long long int *a,unsigned long long int *b){
    unsigned long long int t=*a;
    *a=*b;
    *b=t;
}
int part(unsigned long long int *arr,unsigned long long int l,unsigned long long int r,unsigned long long int x){
    unsigned long long int i;
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

int HowToFindMedian(unsigned long long int *a,unsigned long long int n){
    sort(a,a+n);
    return a[(n)/2];
}

// int ActualMedian(int *a,int l,int r,int k){
//     int n= r-l+1;
//     int i,med[(n+4)/5];
//     int s =n/5 + bool(n%5) ;
//     for( i=0;i<n/5;i++){
//         med[i]= HowToFindMedian(a+l+i*5,5);
        
//     }
//     if(n%5){
//         med[i]= HowToFindMedian(a+l+i*5,n%5);
//         i++;
//     }
//     int medOfMedian;
//     if(i==1){
//         medOfMedian = med[i-1];
//     }
//     else{
//         medOfMedian = ActualMedian(med,0,i-1,i/2);
//     }
//     int pos = part(a,l,r,medOfMedian);
//     if(pos==k){
//         return a[pos];
//     }
//     else if(pos>k){
//         return ActualMedian(a,l,pos-1,k);
//     }
//     else{
//         return ActualMedian(a,pos+1,r,k-pos+l-1);
//     }
//     return INT_MAX;

// }
unsigned long long int ActualMedian(unsigned long long int arr[], unsigned long long int l, unsigned long long int r,unsigned long long  int k) 
{ 

    if (k > 0 && k <= r - l + 1) 
    { 
        unsigned long long int n = r-l+1;
  
        unsigned long long int i, median[(n+4)/5];
        for (i=0; i<n/5; i++) 
            median[i] = HowToFindMedian(arr+l+i*5, 5); 
        if (i*5 < n)  
        { 
            median[i] = HowToFindMedian(arr+l+i*5, n%5);  
            i++; 
        }      
        unsigned long long int medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest(median, 0, i-1, i/2); 
  
        unsigned long long int pos = part(arr, l, r, medOfMed); 
  
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  
            return kthSmallest(arr, l, pos-1, k); 
  
        
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
    return INT_MAX; 
}



int main(){
    unsigned long long int t;cin>>t;
    while(t--){
        unsigned long long int n;cin>>n;
        unsigned long long int a[1000000];
        for(int i=0;i<n;i++){
            long long int x,y;
            cin>>x>>y;
            unsigned long long int d= x*x + y*y;
            a[i]=d;
        }
        unsigned long long int d= kthSmallest(a,0,n-1,(n)/2);
        cout<<pow(d,0.5)<<endl;
    }


}
