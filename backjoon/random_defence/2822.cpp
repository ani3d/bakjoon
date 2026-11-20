#include <iostream>
#include <string.h>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;
int num[9];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int sum=0;
    int order[9];
    int ans[9];
    for(int i=0;i<8;i++){
        cin>>num[i];
        order[i]=num[i];
    }
    
    sort(num,num+8);
    for(int i=3;i<8;i++){
        sum+=num[i];
    }
    cout<<sum<<'\n';
    int k=0;
    for(int i=3;i<8;i++){
        
        for(int j=0;j<8;j++){
            if(num[i]==order[j]){
                ans[k]=j;
                k++;
            }
        }
    }

    sort(ans,ans+5);
    for(int i=0;i<5;i++){
        cout<<ans[i]+1<<' ';
    }





    return 0;
}