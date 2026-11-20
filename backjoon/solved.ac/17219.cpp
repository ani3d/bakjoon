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

    int n,m;
    cin>>n>>m;
    unordered_map<string,string> site;
    string s,pw;
    for(int i=0;i<n;i++){
        cin>>s>>pw;
        site[s]=pw;
    }
    for(int i=0;i<m;i++){
        cin>>s;
        if(site.find(s)!=site.end()){
            cout<<site[s]<<'\n';
        }
    }
    

    return 0;   
}