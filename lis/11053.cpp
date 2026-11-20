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

    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];

    vector<int> tmp;
    tmp.push_back(v[0]);

    for(int i=1;i<n;i++){
        if(tmp.back()<v[i]){
            tmp.push_back(v[i]);
        }
        else{
            auto it=lower_bound(tmp.begin(),tmp.end(),v[i]);
            *it=v[i];
        }
    }
    cout<<tmp.size()<<'\n';

    
    

    return 0;   
}