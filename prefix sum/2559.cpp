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

int n,k;
int degree[100001];
int sum[100001];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>degree[i];
        
    }
    sum[0]=degree[0];
    for(int i=1;i<n;i++){
        sum[i]=sum[i-1]+degree[i];
    }

    long long int max;
    max=sum[k-1];

    for(int i=1;i<=n-k;i++){
        long long int diff=sum[i+k-1]-sum[i-1];
        
        if(max<diff){
            max=diff;
        }
    }
    
    cout<<max;







    return 0;
}