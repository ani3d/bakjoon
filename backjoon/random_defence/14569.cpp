#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<unordered_map>
using namespace std;




int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int n,m,k,t,p,q;
    cin>>n;
    vector<int> studies[1001];
    
    vector<int> realman[10001];
    for(int i=0;i<n;i++){
        cin>>k;
        for(int j=0;j<k;j++){
            cin>>t;
            studies[i].push_back(t);
        }
    }

    cin>>m;
    
    
    int idx1=0,idx2=0;
    while(m--){
        int cnt=0;
        bool flag=true;
        cin>>p;
        int fq;
        bool man[51];
        for(int i=0;i<51;i++){
            man[i]=false;
        } 
        for(int j=0;j<p;j++){
            cin>>q;
            if(j==0) fq=q;
            man[q]=true;
        }
        for(int i=0;i<n;i++){
            // if(studies[i][0]<fq||studies[i].back()>q){
            //     continue;
            // }
            flag=true;
            for(int j=0;j<studies[i].size();j++){
                if(!man[studies[i][j]]){
                    flag=false;
                    break;
                }
            }
            if(flag) cnt++;
        }
        cout<<cnt<<'\n';
    }
    
    

    return 0;   
}