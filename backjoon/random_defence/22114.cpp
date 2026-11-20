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

int dp[100001];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int n,k;
    cin>>n>>k;
    vector<int> len;
    for(int i=0;i<n-1;i++){
        int t;
        cin>>t;
        len.push_back(t);
    }
    int ans=1;
    
    
    for(int i=0;i<n-1;i++){
        int count=1;
        int tmp=0;
        if(n-i<ans) break;

        for(int j=i;j<n-1;j++){
            if(len[j]<=k){
                tmp++;
            }
            else if(len[j]>k&&count==1){
                count--;
                tmp++;
            }
            else if(len[j]>k&&count==0){
                ans=max(tmp,ans);
                break;
            }
        }
        ans=max(ans,tmp);
    }
    cout<<ans+1;
    
   /*
    dp[0]=1;
    for(int i=0;i<n-1;i++){
        int cnt=1;
        int tmp=0;
        for(int j=i;j<n-1;j++){
            if(len[j]<=k){
                tmp++;
                dp[i]=max(dp[i],tmp);
            }
            else if(len[j]>k&&cnt==1){
                cnt--;
                tmp++;
                dp[i]=max(dp[i],tmp);
            }
            else if(len[j]>k&&cnt==0){
                dp[i]=max(dp[i],tmp);
            }
        }
    }
    cout<<dp[n-1];
    */
    return 0;   
}