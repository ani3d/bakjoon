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
    long long int n;
    cin>>n;

    long long int ans=0;
    for(long long int x=0;x<=n;x++){
        if(3*x>n) break;
        ans+=(n-3*x)/2+1;

    }
    
    cout<<ans%1000000;



    return 0;   
}