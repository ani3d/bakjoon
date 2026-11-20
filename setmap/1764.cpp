#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<set>
using namespace std;

int n,m;

string temp;
vector<string> v;
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n>>m;
    int cnt=0;
    set<string> notsee;
    vector<string> ans;

    for(int i=0;i<n;i++){
        cin>>temp;
        notsee.insert(temp);
    }

    for(int i=0;i<m;i++){
        cin>>temp;
        v.push_back(temp);
    }

    sort(v.begin(),v.end());

    
    for(int j=0;j<m;j++){
        if(notsee.find(v[j])==notsee.end()) continue;
        else{
            cnt++;
            ans.push_back(v[j]);
        }
    }

    cout<<cnt<<'\n';
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<'\n';
    }

    



    return 0;
}