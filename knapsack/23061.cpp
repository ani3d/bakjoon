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

int bag[102];
int n,m;
int weight[102];
int value[102];
int dp[1000001];
int ans=1;
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>weight[i]>>value[i];
    }
    int maxbag=0;
    for(int i=1;i<=m;i++){
        cin>>bag[i];
        if(bag[i]>maxbag){
            maxbag=bag[i];
        }
    }
    int idx=0;
    
        
    for(int i=1;i<=n;i++){
        for(int j=maxbag;j>=0;j--){
            if(j<weight[i]) break;
            dp[j]=max(dp[j],dp[j-weight[i]]+value[i]);
        }
    }
    /*
    for(int i=1;i<=m;i++){
        cout<<dp[bag[i]]<<' ';
    }
    cout<<ans<<'\n';
    */
    ans=1;
    for(int i=2;i<=m;i++){
        if(((long long)bag[ans]*dp[bag[i]])>((long long)bag[i]*dp[bag[ans]])){
            ans=i;
        }
    }
    cout<<ans<<'\n';
    

    return 0;   
}