#include<iostream>
#include<vector>
#include<algorithm>

#define mod 1000000007

using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int n;
    cin>>n;
    long long ans=1;
    for(int i=1;i<=n;i++){
        ans=ans*3;
        ans%=mod;
    }
    ans=(ans-1)%mod;

    cout<<ans;
    
   

    return 0;
}