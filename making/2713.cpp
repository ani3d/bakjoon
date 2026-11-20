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
    int t;           //         a       b       c       d       e       f       g       h       i       j       k       l       m       n       o       p        q      r       s       t       u       v       w       x       y       z
    cin>>t;         // 공백     1      2       3       4       5        6       7       8       9       10      11      12      13      14      15      16      17      18      19      20      21      22      23      24      25      26      27      28
    string full[41]={"00000","00001","00010","00011","00100","00101","00110","00111","01000","01001","01010","01011","01100","01101","01110","01111","10000","10001","10010","10011","10100","10101","10110","10111","11000","11001","11010",};
    while(t--){
        int r,c;
        string word;
        cin>>r>>c;
        cin.ignore();
        getline(cin,word);
        
        vector<vector<int>> arr(r,vector<int>(c,-1));
        int cnt=1;
        int i=0,j=0;
        int nn=r,mm=c;
        int dir=0;
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        for(int length=0;length<word.length();length++){
            string temp;
            if(word[length]==' '){
                temp=full[word[length]-' '];
            }
            else temp=full[word[length]-'A'+1];
            
            for(char bit:temp){
                arr[i][j]=bit-'0';

                int nx=i+dx[dir];
                int ny=j+dy[dir];

                if(nx<0||ny<0||nx>=r||ny>=c||arr[nx][ny]!=-1){
                    dir=(dir+1)%4;
                    nx=i+dx[dir];
                    ny=j+dy[dir];
                }
                i=nx;
                j=ny;
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]==-1) arr[i][j]=0;
                cout<<arr[i][j];
            }

        }
        cout<<'\n';
        
    }
    return 0;   
}