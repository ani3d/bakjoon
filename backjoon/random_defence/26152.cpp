#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n;
vector<long long int> a;
vector<long long int> b;
vector<long long int> findn;
int ans=250001;
long long binary(int bird,int start,int end){
    long long res=-1;
    while(start<=end){
        int mid=(start+end)/2;
        if(findn[mid]<bird){
            end=mid-1;
        }
        else{
            res=mid;
            start=mid+1;
        }
    }
    return res+1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    a.resize(n,0);
    b.resize(n,0);
    findn.resize(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    for(int i=0;i<n;i++){
        cin>>b[i];
        if(i==0){
            findn[i]=a[i]-b[i];
        }
        else{
            findn[i]=min(findn[i-1],a[i]-b[i]);
        }
    }
    
    int q;
    cin>>q;
    while(q--){
        int w;
        cin>>w;
        cout<<binary(w,0,n-1)<<'\n';
    }




   
    
    return 0;
}