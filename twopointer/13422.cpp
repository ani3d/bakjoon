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


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int t,n,m,k;
    cin>>t;
    while(t--){
        cin>>n>>m>>k;
        int ans=0;
        vector<long long int> house;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            house.push_back(temp);
        }
        if(n==m){
            long long sum=0;
            for(int i=0;i<n;i++) sum+=house[i];
            if(sum<k) cout<<1<<'\n';
            else cout<<0<<'\n';
            continue;
        }
        for(int i=0;i<m-1;i++){
            house.push_back(house[i]);
        }
        long long int sum=0;
        for(int i=0;i<m;i++){
            sum+=house[i];
        }
        if(sum<k){
            ans++;
        }
        
        for(int i=m;i<n+m-1;i++){
            sum=sum+house[i];
            sum=sum-house[i-m];
            if(sum<k){
                ans++;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;   
}