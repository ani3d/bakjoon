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

int n;

unordered_map<string,int> map;


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int cnt=0;    
    cin>>n;

    vector<string> in(n);
    vector<string> out(n);

    for(int i=0;i<n;i++){
        cin>>in[i];
    }

    for(int i=0;i<n;i++){
        cin>>out[i];
    }

    for(int i=0;i<in.size();i++){
        map[in[i]]=i;
    }

    for(int i=0;i<out.size();i++){
        for(int j=1+i;j<out.size();j++){
            if(map[out[i]]>map[out[j]]){
                cnt++;
                break;
            }
        }
    }

    cout<<cnt;


    return 0;
}