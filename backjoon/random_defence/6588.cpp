#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;
int num=1000001;
int arathos[1000001];

void sieve(){
    for(int i=2;i<=num;i++){
        arathos[i]=i;
    }

    for(int i=2;i<=sqrt(num);i++){
        if(arathos[i]==0){
            continue;
        }
        for(int j=i*i;j<=num;j+=i){
            arathos[j]=0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    sieve();

    int n;
    int a,b;
    while(1){
        
        cin>>n;
        if(n==0) break;
        bool flag=false;
        for(int i=2;i<=n;i++){
            if(arathos[i]&&arathos[n-i]){
                flag=true;
                cout<<n<<" = "<<arathos[i]<<" + "<<arathos[n-i]<<"\n";
                break;
            }
            
        }
        if(flag==false){
            cout<<"Goldbach's conjecture is wrong.\n";
        }

        
    }
    



    return 0;
}