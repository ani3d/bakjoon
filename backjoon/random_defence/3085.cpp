#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int ans=0;
int cnt=1;
int n;

char board[51][51];

int check(){
    for(int i=0;i<n;i++){
        cnt=1;
        for(int j=0;j<n;j++){
            if(board[i][j]==board[i][j+1]){
                cnt++;
            }
            else{
                ans=max(cnt,ans);
                cnt=1;
            }

        }
    }
    for(int i=0;i<n;i++){
        cnt=1;
        for(int j=0;j<n;j++){
            if(board[j][i]==board[j+1][i]){
                cnt++;
            }
            else{
                ans=max(cnt,ans);
                cnt=1;
            }
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    cin>>n;
    

    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>board[i][j];
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            swap(board[i][j],board[i][j+1]);
            check();
            swap(board[i][j],board[i][j+1]);
            swap(board[j][i],board[j+1][i]);
            check();
            swap(board[j][i],board[j+1][i]);
        }
    }

    cout<<ans<<'\n';




    return 0;
}