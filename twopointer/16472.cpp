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
    int n;
    cin>>n;
    string word;
    cin>>word;
    int st,ed;
    st=0;
    ed=word.length();
    int ans=0;
    int dist=0;
    int visit[26]={0,};
    for(int r=0;r<ed;r++){
        int idx=word[r]-'a';
        if(visit[idx]==0) dist++;
        visit[idx]++;
        while(dist>n){
            int idxst=word[st]-'a';
            visit[idxst]--;
            if(visit[idxst]==0)dist--;
            st++;
        }
        ans=max(ans,r-st+1);
    }
    cout<<ans<<'\n';
    


    
    return 0;   
}