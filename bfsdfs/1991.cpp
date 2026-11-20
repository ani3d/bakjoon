#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;


int n;
pair<char,char> node[26];

void pre(char cur){
    if(cur=='.')
    return;

    cout<<cur;
    pre(node[cur-'A'].first);
    pre(node[cur-'A'].second);
}

void in(char cur){
    if(cur=='.') return;

    in(node[cur-'A'].first);
    cout<<cur;
    in(node[cur-'A'].second);
}

void post(char cur){
    if(cur=='.') return;

    post(node[cur-'A'].first);
    post(node[cur-'A'].second);
    cout<<cur;
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    cin>>n;
    for(int i=0;i<n;i++){
        char pa,lt,rt;
        cin>>pa>>lt>>rt;

        node[pa-'A'].first=lt;
        node[pa-'A'].second=rt;

    }
    pre('A');
    cout<<'\n';
    in('A');
    cout<<'\n';
    post('A');

    



    return 0;
}