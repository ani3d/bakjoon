#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int map[17][17];
int dp[17][17][3];//0 가로 1 대각 2 세로
int n;
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    dp[0][1][0]=1;
    for(int i=2;i<n;i++){
        if(!map[0][i]){
            dp[0][i][0]=dp[0][i-1][0];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=2;j<n;j++){
            if(!map[i][j]){
                dp[i][j][0]=dp[i][j-1][0]+dp[i][j-1][1];
                dp[i][j][2]=dp[i-1][j][1]+dp[i-1][j][2];
                if(!map[i-1][j]&&!map[i][j-1]){
                    dp[i][j][1]=dp[i-1][j-1][0]+dp[i-1][j-1][1]+dp[i-1][j-1][2];
                }
            }
        }
    }
    cout<<dp[n-1][n-1][0]+dp[n-1][n-1][1]+dp[n-1][n-1][2];



    return 0;
}