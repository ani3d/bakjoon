#include <iostream>
#include <string.h>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

typedef struct{
    string word;
    int len;
}book;

bool comp(const book & a,const book & b){
    if(a.len==b.len){
        return a.word<b.word;
    }
    else return a.len<b.len;
}

int main() {
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    int n;
    cin>>n;
    book list[20001];
    for(int i=0;i<n;i++){
        cin>>list[i].word;
        list[i].len=list[i].word.length();
    }
    
    sort(list,list+n,comp);
    
    for(int i=0;i<n;i++){
        if(list[i].word==list[i-1].word) continue;
        cout<<list[i].word<<'\n';
        
    }
    
    
    
    
    
    
    return 0;
}