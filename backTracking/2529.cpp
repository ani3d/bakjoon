#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<map>
#include<climits>

using namespace std;
vector<char> ord;
bool visit[10];
string minAnsStr,maxAnsStr;
long long minAns=LLONG_MAX,maxAns=LLONG_MIN;
int n;

void dfs(vector<int>& ps,int index,int prev){
    if(ps.size()==n+1){
        string temp;
        long long val=0;
        for(auto &t:ps){
            temp+=to_string(t);
            val=val*10+t;
        }
        if(val<minAns){
            minAns=val;
            minAnsStr=temp;
        }
        if(val>maxAns){
            maxAns=val;
            maxAnsStr=temp;
        }
        temp.clear();
        return;
    }

    if(ord[index]=='<'){
        for(int next=prev+1;next<=9;next++){
            if(!visit[next]){
                visit[next]=true;
                ps.push_back(next);
                dfs(ps,index+1,next);
                visit[next]=false;
                ps.pop_back();
            }
        }
    }
    else{
        for(int next=prev-1;next>=0;next--){
            if(!visit[next]){
                visit[next]=true;
                ps.push_back(next);

                dfs(ps,index+1,next);

                visit[next]=false;
                ps.pop_back();
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    cin>>n;
    ord.resize(n);
    
    for(int i=0;i<n;i++){
        cin>>ord[i];
    }
    vector<int> ps;
    for(int i=0;i<=9;i++){
        visit[i]=true;
        ps.push_back(i);
        dfs(ps,0,i);
        visit[i]=false;
        ps.pop_back();
    }
    cout<<maxAnsStr<<'\n'<<minAnsStr;
    

    

    return 0;   
}