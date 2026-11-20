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


struct study{
    int value;
    int time;
};
int dp[10001];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    vector<study> studies(k+1);

    for(int i=1;i<=k;i++){
        cin>>studies[i].value>>studies[i].time;
    }
    for(int i=0;i<=n;i++){
        dp[i]=0;
    }

    for(int i=1;i<=k;i++){
        for(int j=n;j>=studies[i].time;j--){
            dp[j]=max(dp[j],dp[j-studies[i].time]+studies[i].value);
        }
    }
    cout<<dp[n]<<'\n';

    

    return 0;   
}