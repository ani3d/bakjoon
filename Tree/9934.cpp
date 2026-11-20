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

vector<int> v;
vector<int> height[1025];



void inorder(int start,int end,int level){

    if(start>end) return;
    int mid=(start+end)/2;

    height[level].push_back(v[mid]);

    inorder(start,mid-1,level+1);
    inorder(mid+1,end,level+1);
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int k; cin>>k;
    int n=(1<<k)-1;

    v.resize(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    

    inorder(0,n-1,1);

    for(int i=1;i<=k;i++){
        for(auto it:height[i]){
            cout<<it<<' ';
        }
        cout<<'\n';
    }

    




    return 0;
}