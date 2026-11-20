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

vector<int> tri;

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int n,num; cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        tri.push_back(num);
    }
    sort(tri.begin(),tri.end(),greater<int>());
    int maxn;
    int rest;
    int maxlength=-1;
    for(int i=0;i<n-2;i++){
        maxn=tri[i];
        rest=tri[i+1]+tri[i+2];
        if(maxn>=rest){
            continue;
        }
        else maxlength=max(maxlength,maxn+rest);
    }
    cout<<maxlength;







    return 0;
}