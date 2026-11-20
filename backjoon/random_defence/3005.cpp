#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;
string board[20];

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    
    int r,c;
    cin>>r>>c;
    for(int i=0;i<r;i++){
        cin>>board[i];
    }

    string ans="zzzzzzzzzzzzzzzz";

    for(int i=0;i<r;i++){
        string s="";
        for(int j=0;j<c;j++){
            if(board[i][j]=='#'){
                if(s.length()>=2&&ans>s) ans=s;
                s="";
            }
            else s+=board[i][j];
        }
        if(s.length()>=2&&ans>s) ans=s;
    }

    for(int j=0;j<c;j++){
        string s="";
        for(int i=0;i<r;i++){
            if(board[i][j]=='#'){
                if(s.length()>=2&&ans>s) ans=s;
                s="";
            }
            else s+=board[i][j];
        }
        if(s.length()>=2&&ans>s) ans=s;
        
    }
    
    cout<<ans;



    return 0;
}