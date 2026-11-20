#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int t;
int x1,y1;
char x2,y2;
int visit[9][9];
int map[9][9];
int dx[]={1,-1,1,-1};
int dy[]={-1,-1,1,1};
int cnt;
pair<char,int> p;
queue<pair<int,int>> q;
void bfs(int x,int y){
    q.push({x,y});
    visit[x][y]=1;
    while(!q.empty()){
        int a=q.front().first;
        int b=q.front().second;
        q.pop();
        if(x+'A'==y2&&y==y1){
            cout<<cnt<<' ';
            cout<<p.first<<' '<<p.second;
            cout<<y2<<' '<<y1;
        }
        p=make_pair(a+'A',b);

        for(int i=0;i<4;i++){
            int na=a+dx[i];
            int nb=b+dy[i];
            if(na<0||na>=8||nb<0||nb>=8) continue;
            if(visit[na][nb]) continue;
            q.push({na,nb});
            visit[na][nb]=true;
            cnt++;
        }
    }

}
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>x2>>x1>>y2>>y1;

        if(abs((int)(x2-y2))%2==0){
            if(abs((int)(y1-x1))%2==0){
                bfs(x2-'A',x1);
            }
            else cout<<"Impossible\n";
        }
        else if(abs((int)(x2-y2))%2!=0){
            if(abs(y1-x1)%2==0){
                cout<<"Impossible\n";
            }
            else bfs(x2-'A',x1);
        }
    }


    return 0;
}