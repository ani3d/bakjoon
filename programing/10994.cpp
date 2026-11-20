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
char arr[400][400];

void draw(int len,int row,int col){
    for(int i=0;i<len;i++){
        if(i==0||i==len-1){
            for(int j=0;j<len;j++){
                arr[row+i][col+j]='*';
            }
        }
        else{
            arr[row+i][col]='*';
            arr[row+i][col+len-1]='*';
        }
    }
}

void square(int n,int row,int col){
    int len=4*n-3;
    draw(len,row,col);
    if(n==1){
        return;
    }
    square(n-1,row+2,col+2);
}


int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<4*n-3;i++){
       for(int j=0;j<4*n-3;j++){
            arr[i][j]=' ';
        } 
    }
    square(n,0,0);
    for(int i=0;i<4*n-3;i++){
        for(int j=0;j<4*n-3;j++){
            cout<<arr[i][j];
        }
        cout<<'\n';
    }
    

    

    return 0;   
}