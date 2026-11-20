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

vector<int> ans;
int n,m;
void dfs(int index,int s){
    if(index==m){
        for(int i=0;i<m;i++){
            cout<<ans[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=s;i<=n;i++){
            ans.push_back(i);
            dfs(index+1,i);
            ans.pop_back();
    }



}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n>>m;
    ans.reserve(n);
    dfs(0,1);


    

    return 0;   
}