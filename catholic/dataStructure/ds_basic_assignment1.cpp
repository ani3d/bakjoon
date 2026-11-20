#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<map>
#include<iomanip>
using namespace std;

vector<int> tree;
int height=0;
int width=0;

vector<string> canvas;

void draw(int idx,int row,int col,int gap){
    if(idx>=tree.size()||tree[idx]==0) return;
    
    string val=to_string(tree[idx]);
    for(int i=0;i<val.size();i++){
        if(col+i<width) canvas[row][col+i]=val[i];
    }

    int left=idx*2;
    if(left<tree.size()&&tree[left]!=0){
        canvas[row+1][col-gap]='/';
        draw(left,row+2,col-gap*2,gap/2);
    }
    int right=idx*2+1;
    if(right<tree.size()&&tree[right]!=0){
        canvas[row+1][col+gap]='\\';
        draw(right,row+2,col+gap*2,gap/2);
    }
    

    

}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n;
    cin>>n;
    tree.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>tree[i];
    }

    int depth=0;
    int temp=n;

    while(temp>0){
        temp/=2;
        depth++;
    }
    height=depth*2;
    width=(1<<(depth+1));
    canvas.assign(height,string(width,' '));
    draw(1,0,width/2,width/8);

    for(string& line:canvas){
        cout<<line<<'\n';
    }
    


    return 0;
}