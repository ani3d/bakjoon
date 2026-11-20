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
    int m,n;
    cin>>m>>n;
    map<int,int> space;
    map<int,int> pic;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        space[x]=y;
    }
    for(int j=0;j<n;j++){
        int x,y;
        cin>>x>>y;
        pic[x]=y;
    }
    return 0;   
}