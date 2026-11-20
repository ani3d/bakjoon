#include <iostream>
#include <string.h>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<cmath>
using namespace std;

char in[10]={ '.', 'O', '|', '-', '/', '\\', '^', '<', 'v', '>' };
char out[10]={'.', 'O', '-', '|', '\\', '/', '<', 'v', '>', '^' };

int main() {
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    int n,m;
    
    cin>>n>>m;
    char word[101][101];
    char rword[101][101];
    for(int i=0;i<n;i++){
        cin>>word[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<10;k++){
                if(word[i][j]==in[k]){
                    word[i][j]=out[k];
                    break;
                }
            }
        }
    }

    for(int i=m-1;i>=0;i--){
        for(int j=0;j<n;j++){
            cout<<word[j][i];
        }
        cout<<'\n';
    }








    return 0;
}
