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
    int n;cin>>n;
    int arr[50001];
    vector<pair<int,int>> orbit(n+1);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    orbit[0]={0,arr[0]};
    int temp=arr[0];
;
    for(int i=1;i<n;i++){
        temp+=arr[i]*2;
        orbit[i].first=temp-arr[i];
        if(i==1) orbit[i].first=arr[0]+arr[1];
        orbit[i].second=arr[i];
    }
    int lean[50001];
    int sum=0;
    int first,second;
    for(int i=1;i<n;i++){
        first=(orbit[i].second-orbit[i-1].second)*(orbit[i].second-orbit[i-1].second)+(orbit[i].first-orbit[i-1].first)*(orbit[i].first-orbit[i-1].first);
        sum+=first;
    }
    
    cout<<sum;

    return 0;   
}