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

vector<pair<long long int,long long int>> line;

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n;
    cin>>n;
    line;
    for(int i=0;i<n;i++){
        int x,y;
        cin>>x>>y;
        line.push_back({x,y});
    }

    long long int sum=0;

    for(int i=0;i<n-1;i++){
        if(line[i+1].first<=line[i].second){
            line[i+1].first=line[i].first;
            line[i+1].second=max(line[i+1].second,line[i].second);
        }
        else{
            sum+=line[i].second-line[i].first;
            
        }
    }
    sum+=line[n-1].second-line[n-1].first;

    cout<<sum;
    

    return 0;   
}