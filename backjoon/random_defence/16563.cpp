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


int len=5000001;
int prime[5000001];
void erathos(){
    for(int i=2;i<=len;i++){
        prime[i]=i;
    }
    int sqrtn=(int)(sqrt(len));
    for(int i=2;i<=sqrtn;i++){
        for(int j=i*i;j<len;j+=i){
            if(prime[j]==j){
                prime[j]=i;
            }
        }
    }
}
void solution(int n){
    while(n>1){
        cout<<prime[n]<<' ';
        n/=prime[n];
    }
    cout<<'\n';
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n;
    erathos();
    for(int i=0;i<n;i++){

        int num;
        cin>>num;
        solution(num);
    }
    

    return 0;   
}