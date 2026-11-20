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

int dp[1000001];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int n,m;
    cin>>n>>m;
    dp[0]=1;
    
    for(int i=1;i<=n;i++){
        dp[i]=dp[i-1];
        if(i>=m) dp[i]=(dp[i]+dp[i-m])%1000000007;
    }
    cout<<dp[n]%1000000007;
    

    return 0;   
}