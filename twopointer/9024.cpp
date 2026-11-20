#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<map>

#define INF 1e9
using namespace std;

int t,k,n;
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    cin>>t;
    while(t--){
        
        cin>>n>>k;
        vector<int> num(n);
        long long int min=INF;
        
        long long int sum;
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>num[i];
        }
        sort(num.begin(),num.end());
        int st=0;
        int ed=n-1;
        while(st<ed){
            sum=num[st]+num[ed];
            long long less=llabs(sum-k);

            if(less<min){
                min=less;
                ans=1;
            }
            else if(less==min){
                ans++;
            }
            if(sum<k)st++;
            else ed--;

        }
        cout<<ans<<'\n';
        
    }

    return 0;   
}