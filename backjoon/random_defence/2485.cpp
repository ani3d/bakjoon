#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<map>
using namespace std;

int euc(int a,int b){
    int r=a%b;
    if(r==0) return b;
    return euc(b,r);
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int n;
    int ans=0;
    int gcd=0;
    int dif[100001];
    int arr[100001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n-1;i++){
        dif[i]=arr[i+1]-arr[i];
    }
    
    gcd=dif[0];
    for(int i=1;i<n-1;i++){
        gcd=euc(gcd,dif[i]);
    }
    for(int i=1;i<n;i++){
        ans+=(arr[i]-arr[i-1])/gcd-1;
    }

    cout<<ans;


    



    return 0;
}