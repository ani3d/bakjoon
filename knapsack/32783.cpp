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
const int MOD=1e9+7;
int eff=96;




int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    

    long long int money[10001];
    long long int minute[10001];
    int mpm[10001];

    int dp[300001];
    int c1,c2,n,a;
    int m;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>money[i]>>minute[i];
        mpm[i]=((eff*money[i]*minute[i])/(1000*60));

    }
    
    cin>>c1>>c2;
    dp[0]=1;
    for(int i=1;i<=n;i++){
        for(int j=c2;j>=mpm[i];j--){
            dp[j]=(dp[j]+dp[j-mpm[i]])%MOD;
        }
    }
    long long ans=0;
    for(int j=c1;j<=c2;j++){
        ans=(ans+dp[j])%MOD;
    }
    if(c1==0)ans=(ans-1+MOD)%MOD;
    cout<<ans;



    

    

    return 0;   
}
