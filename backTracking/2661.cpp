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

string ans;
int n;
bool bad(string str){
    int len=str.length();
    int half=len/2;

    for(int i=1;i<=half;i++){
        string first=str.substr(len-(i*2),i);
        string second=str.substr(len-i,i);
        if(first==second){
            return true;
        }
    }
    return false;

}
void dfs(int index,string str){
    if(bad(str)) return;

    if(index==n){
        cout<<str<<'\n';
        exit(0);
    }
    dfs(index+1,str+'1');
    dfs(index+1,str+'2');
    dfs(index+1,str+'3');

}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    cin>>n;

    dfs(0,"");

    

    return 0;   
}