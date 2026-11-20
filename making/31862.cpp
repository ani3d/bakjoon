#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<map>
#include<unordered_set>
using namespace std;


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n,m,k;
    cin>>n>>m>>k;
    int ans=0;
    vector<int> teamscore(n+1,0);
    vector<pair<int,int>> t1;
    
    int win;
    for(int i=0;i<m;i++){
        int temp1,temp2;
        cin>>temp1>>temp2>>win;
        if(win==1){
            teamscore[temp1]++;
        }
        else if(win==2){
            teamscore[temp2]++;
        }
        else {
            t1.push_back({temp1,temp2});
            
        }
    }
    
    
    for(int i=0;i<(1<<t1.size());i++){
        vector<int> modify;
        unordered_set<int> affect;
        

        for(int j=0;j<t1.size();j++){
            if(i&(1<<j)){
                teamscore[t1[j].first]++;
                modify.push_back(t1[j].first);
                affect.insert(t1[j].first);
            }
            else{
                teamscore[t1[j].second]++;
                modify.push_back(t1[j].second);
                affect.insert(t1[j].second);
            }
        }

        int max=-1,best=-1;
        for(auto team : affect){
            if(teamscore[team]>max){
                max=teamscore[team];
                best=team;
            }
            else if(teamscore[team]==max){
                best=-1;
            }
        }
        if(teamscore[k]>max){
            max=teamscore[k];
            best=k;
        }
        else if(teamscore[k]==max&&best!=k){
            best=-1;
        }
        if(best==k){
            ans++;
        }

        for(int team:modify){
            teamscore[team]--;
        }

    }
    

    cout<<ans;

    return 0;   
}