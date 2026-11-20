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
int n,m;
vector<int> ans;
vector<vector<int>> pred;
bool possible=false;
bool tie=true;
int ansanble=0;
int score(const vector<int>& ones,int k){
    int acc=0;
    int half=k/2;
    for(int j=0;j<m;j++){
        int y=(ones[j]>half)?1:0;
        if(y==ans[j])++acc;
    }
    return acc;
}
void dfs(int idx,int k,vector<int>& ones){
    if(possible) return;

    if(k>=3&&(k%2)==1){
        int acc=score(ones,k);
        if(acc>ansanble){possible=true;return;}
    }
    if(idx==n){
        return;
    }

    int nextodd=(k&1)?k:(k+1);
    if(nextodd<3) nextodd=3;
    if(k+(n-idx)<nextodd) return;

    for(int j=0;j<m;j++) ones[j]+=pred[idx][j];
    dfs(idx+1,k+1,ones);
    for(int j=0;j<m;j++){
        ones[j]-=pred[idx][j];
    }
    dfs(idx+1,k,ones);
}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    
    cin>>n>>m;
    ans.resize(m,0);
    
    for(int i=0;i<m;i++){
        int temp;
        cin>>ans[i];
    }
    pred.assign(n,vector<int>(m));
    for(int i=0;i<n;i++){
        int temp;
        for(int j=0;j<m;j++){
            cin>>pred[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int temp=0;
        for(int j=0;j<m;j++){
            if(pred[i][j]==ans[j]){
                temp++;
            }
        }
        ansanble=max(ansanble,temp);
    }
    
    vector<int> ones(m,0);
    dfs(0,0,ones);

    cout<<(possible?1:0)<<'\n';
    



    

    return 0;   
}