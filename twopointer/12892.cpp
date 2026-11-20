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

bool comp(pair<long long int,long long int> a,pair<long long int,long long int> b){
    return b.first>a.first;
} 

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n,p,v,d;
    cin>>n>>d;
    vector<pair<int,int>> num;
    for(int i=0;i<n;i++){
        int n1,n2;
        cin>>n1>>n2;
        num.push_back({n1,n2});   
    }
    long long int sum=0;
    long long int diff;
    long long int hpy=0;
    long long int ans=0;
    sort(num.begin(),num.end(),comp);
    
    int st;
    st=0;
    
    for(int ed=0;ed<n;ed++){
        sum+=num[ed].second;
        while(num[ed].first-num[st].first>=d){
            sum-=num[st].second;
            st++;
        }
        ans=max(ans,sum);

    }
    cout<<ans;



    return 0;   
}