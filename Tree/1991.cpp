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

int n;
pair<char,char> node[26];


void pre(char cur){
    if(cur=='.') return;

    cout<<cur;
    pre(node[cur-'A'].first);
    pre(node[cur-'A'].second);
}

void mid(char cur){
    if(cur=='.') return;

    mid(node[cur-'A'].first);
    cout<<cur;
    mid(node[cur-'A'].second);
}

void aft(char cur){
    if(cur=='.') return;

    aft(node[cur-'A'].first);
    aft(node[cur-'A'].second);
    cout<<cur;
}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    cin>>n;

    char nd,lt,rt;
    for(int i=0;i<n;i++){
        cin>>nd>>lt>>rt;

        node[nd-'A'].first=lt;
        node[nd-'A'].second=rt;
    }
    
    pre('A');
    cout<<'\n';
    mid('A');
    cout<<'\n';
    aft('A');


    return 0;
}