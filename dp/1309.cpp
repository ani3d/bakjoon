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

int dp[1000001][3];
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    dp[1][0]=1;
    dp[1][1]=1;
    dp[1][2]=1;

    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        dp[i][0]=(dp[i-1][0]+dp[i-1][1]+dp[i-1][2])%9901;
        dp[i][1]=(dp[i-1][0]+dp[i-1][2])%9901;
        dp[i][2]=(dp[i-1][1]+dp[i-1][0])%9901;
    }
    int sum=(dp[n][0]+dp[n][1]+dp[n][2])%9901;
    cout<<sum;
    

    return 0;   
}