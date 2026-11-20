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

int solve(vector<int> &arr){
    
    int n=arr.size();
    int best=0;

    for(int start=0;start<n;start++){
        vector<int> seq(n);
        for(int i=0;i<n;i++){
            seq[i]=arr[(start+i)%n];

        }
        vector<int> dp(n,1);
        int localmax=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(seq[j]<seq[i]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            localmax=max(localmax,dp[i]);
        }best=max(best,localmax);
    }
    return best;
    
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> yj(n),hg(n);
    for(int i=0;i<n;i++){
        cin>>yj[i];
    }
    for(int i=0;i<n;i++){
        cin>>hg[i];
    }
    
    int yjscr=0,hgscr=0;
    
    yjscr=solve(yj);
    hgscr=solve(hg);
    
    if(hgscr>yjscr){
        cout<<"HG Win!"<<'\n';
    }
    else if(hgscr==yjscr){
        cout<<"Both Win!"<<'\n';
    }
    else cout<<"YJ Win!"<<'\n';
    


    return 0;   
}