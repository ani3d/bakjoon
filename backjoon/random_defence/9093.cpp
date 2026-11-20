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
    int t;cin>>t;
    cin.ignore();
    while(t--){
        stack<char> s;
        string word;
        getline(cin,word);
        word+=' ';
        for(int i=0;i<word.size();i++){
            if(word[i]==' '){
                while(!s.empty()){
                    cout<<s.top();
                    s.pop();
                }cout<<' ';
            }
            else s.push(word[i]);
        }        
        cout<<'\n';
    }
    

    return 0;   
}