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

long long int dp[65][10];
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    
    for(int i=0;i<=9;i++){
        dp[1][i]=1;
    }
    for(int i=2;i<=64;i++){
        for(int j=0;j<=9;j++){
            for(int k=j;k<=9;k++){
                dp[i][j]+=dp[i-1][k];
            }
        }
    }
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        long long result=0;
        for(int i=0;i<=9;i++){
            result+=dp[n][i];
        }
        cout<<result<<'\n';
        
        

        

    }


    return 0;   
}