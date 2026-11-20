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
    int money[100001];
    int n;
    cin>>n;
    
    int maxmoney;
    int temp[100001];
    long long int answer=0;
    for(int i=0;i<n;i++){
        cin>>money[i];
        temp[i]=money[i];
    }

    while(1){
        int maxval=-1;
        int maxidx=-1;
        for(int i=0;i<n;i++){
            if(money[i]>maxval){
                maxval=money[i];
                maxidx=i;
            }
        }
        if(maxval==-1)break;
        int cnt=0;
        int sum=0;
        for(int i=0;i<maxidx;i++){
            if(money[i]!=-1){
                sum+=money[i];
                cnt++;
                money[i]=-1;
            }
        }
        answer+=maxval*cnt-sum;
        money[maxidx]=-1;
    }
    cout<<answer;

    return 0;   
}