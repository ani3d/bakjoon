#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<map>
#include<set>
using namespace std;


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>> train(n+1,vector<int>(21,0));
    
    for(int i=0;i<m;i++){
        int ord;
        int tnum;
        int snum;
        cin>>ord;
        if(ord==1){
            cin>>tnum>>snum;
            if(train[tnum][snum]==0){
                train[tnum][snum]=1;
            }
        }
        if(ord==2){
            cin>>tnum>>snum;
            if(train[tnum][snum]==1){
                train[tnum][snum]=0;
            }
        }
        if(ord==3){
            cin>>tnum;
            
            for(int i=19;i>=1;i--){
                train[tnum][i+1]=train[tnum][i];
            }
            train[tnum][1]=0;
        }
        if(ord==4){
            cin>>tnum;
            for(int i=2;i<=20;i++){
                train[tnum][i-1]=train[tnum][i];
            }
            train[tnum][20]=0;

        }
            
    }
    set<vector<int>> unique;
    for(int i=1;i<=n;i++){
        unique.insert(train[i]);
    }
    cout<<unique.size();

    return 0;   
}