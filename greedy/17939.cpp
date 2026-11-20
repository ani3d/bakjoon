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
    int max=0;
    for(int i=n-1;i>=0;i--){
        if(money[i]>max){
            max=money[i];
        }
        else{
            answer+=(max-money[i]);
        }
    }
    cout<<answer;

    return 0;   
}