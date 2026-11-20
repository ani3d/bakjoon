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

    int n,t;
    
    cin>>t;
    while(t--){
        cin>>n;
        int checkpoint[n+2];
        int index=1;
        long long int sum=0;
        long long int maxsum;
        int check;
        for(int i=1;i<=n;i++){
            cin>>checkpoint[i];
        }
        for(int i=2;i<=n;i++){
            sum+=abs(checkpoint[i]-checkpoint[i-1]);
        }
        long long mxskip=0;
        for(int i=2;i<n;i++){
            
            long long origin=abs(checkpoint[i]-checkpoint[i-1])+abs(checkpoint[i+1]-checkpoint[i]);
            long long skip=abs(checkpoint[i+1]-checkpoint[i-1]);
            long long save=origin-skip;
            if(save>mxskip){
                mxskip=save;
            }
        }

        cout<<sum-mxskip<<'\n';
        cout.flush();
    }



    return 0;
}