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

int n;
int num[51];
int temp[51];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
        temp[i]=num[i];
    }

    long long int cnt=0;
    
    while(true){
        bool act=false;
        for(int i=1;i<n-1;i++){
            if(num[i]*2>num[i-1]+num[i+1]){
                num[i]=((num[i-1]+num[i+1])/2);
                act=true;
            }
        }
        if(act==false) break;
    }
    
    for(int i=0;i<n;i++){
        cnt+=temp[i]-num[i];
    }
    cout<<cnt;
    return 0;
}