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
bool compare(pair<string,int> a,pair<string,int> b){
    return a.second<b.second;
}
string binary_search(vector<pair<string,int>>& v,int num){
    int low=0;
    int high=v.size()-1;
    string ans;

    while(low<=high){
        int mid=(low+high)/2;
        if(v[mid].second>=num){
            ans=v[mid].first;
            high=mid-1;
        }
        else low=mid+1;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int n,m;
    cin>>n>>m;
    string pwcode;
    int ratenum;
    vector<pair<string,int>> power;
    for(int i=0;i<n;i++){
        cin>>pwcode>>ratenum;
        power.push_back({pwcode,ratenum});
    }
    
    int score;
    for(int i=0;i<m;i++){
        cin>>score;
        cout<<binary_search(power,score)<<'\n';
        
    }

    




    return 0;
}