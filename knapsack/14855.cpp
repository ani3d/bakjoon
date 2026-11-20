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

struct dump{
    int restin;
    int needin;
    int needmil;
    int money;
};
int dp[10001][10];
vector<dump> dumplings(11);
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int n,m,spc,spcm;
    cin>>n>>m>>dumplings[0].needmil>>dumplings[0].money;
    
    int Bound[11];
    
    
    for(int i=1;i<=m;i++){
        cin>>dumplings[i].restin>>dumplings[i].needin>>dumplings[i].needmil>>dumplings[i].money;
    }
    Bound[0]=n/dumplings[0].needmil;
    
    int idx=1;
    for(int i=1;i<=m;i++){
        Bound[i]=min((dumplings[i].restin/dumplings[i].needin),n/dumplings[i].needmil);
    }
    int ans=0;
    for(int i=0;i<=m;i++){
        for(int j=1;j<=Bound[i];j++){
            for(int k=n;k>=0;k--){
                if(k-dumplings[i].needmil>=0){
                    dp[idx][k]=max(dp[idx-1][k],dp[idx-1][k-dumplings[i].needmil]+dumplings[i].money);
                }
                else{
                    dp[idx][k]=dp[idx-1][k];
                }
                ans=max(ans,dp[idx][k]);
            }
            idx++;
        }
    }

    cout<<ans;

    return 0;   
}