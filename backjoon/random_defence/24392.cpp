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
#define MOD 1'000'000'007

long long int dp[1001][1001];
long long int arr[1001][1001];
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n,m;cin>>n>>m;
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            cin>>arr[i][j];
        }
    }
    for(int j=0;j<m;j++){
        if(arr[0][j]==1) dp[0][j]=1;
    }
    
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==1){
                if(j==0){
                    if(arr[i-1][j+1]==1){
                        dp[i][j]+=dp[i-1][j+1]%MOD;
                    }
                    if(arr[i-1][j]==1){
                        dp[i][j]+=dp[i-1][j]%MOD;
                    }
                    
                }
                else if(j==m-1){
                    if(arr[i-1][j-1]==1){
                        dp[i][j]+=dp[i-1][j-1]%MOD;
                    }
                    if(arr[i-1][j]==1){
                        dp[i][j]+=dp[i-1][j]%MOD;
                    }
                    
                }
                else{
                    if(arr[i-1][j-1]==1){
                        dp[i][j]+=dp[i-1][j-1]%MOD;
                    }
                    if(arr[i-1][j]==1){
                        dp[i][j]+=dp[i-1][j]%MOD;
                    }
                    if(arr[i-1][j+1]==1){
                        dp[i][j]+=dp[i-1][j+1]%MOD;
                    }
                }
                
            }
        }
    }
    long long int ans=0;

    for(int i=0;i<m;i++){
        ans+=dp[n-1][i];
        ans%=MOD;
    }
    cout<<ans;
    
    

    return 0;   
}