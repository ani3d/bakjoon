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
    long long int n;cin>>n;
    vector<long long int> like;
    for(int i=0;i<n;i++){
        long long int x;
        cin>>x;
        like.push_back(x);
    }
    long long int l;cin>>l;
    
    long long int start=0;
    long long int maxa=*max_element(like.begin(),like.end());
    long long int end=max(maxa,(l+n-1)/n);
    long long int result=0;
    long long int ans;

    while(start<=end){
        long long int total=0;
        long long int mid=(start+end)/2;
        for(auto i=0;i<n;i++){
            if(like[i]>mid) {
                total+=2*(mid-like[i]);
            }
            else total+=mid;
        }
        
        if(total>=l){
            ans=mid;
            end=mid-1;
        }
        else start=mid+1;
    }

    cout<<ans;
    return 0;   
}