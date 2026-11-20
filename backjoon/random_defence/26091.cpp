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


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n,m; cin>>n>>m;
    vector<int> man;
    int cnt=0;
    int unuse=n;
    
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        man.push_back(temp);
    }
    sort(man.begin(),man.end());
        int st=0;
        int ed=n-1;
        while(st<ed){
            if(man[st]+man[ed]>=m){
                cnt++;
                st++;
                ed--;
                unuse-=2;
            }
            else st++;
        } 
    cout<<cnt<<'\n';

    return 0;   
}