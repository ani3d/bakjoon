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
    int n,k;
    int money[11];
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>money[i];
    }
    sort(money,money+n,greater<>());
    int cnt=0;
    while(1){
        if(k==0) break;
        for(int i=0;i<n;i++){
            if(money[i]<=k){
                int temp=k/money[i];
                k=k-money[i]*temp;
                cnt+=temp;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;   
}