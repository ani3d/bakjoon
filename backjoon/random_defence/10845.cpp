#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
using namespace std;

int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    int n,x;
    cin>>n;
    queue<int> que;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        if(s=="push"){
            cin>>x;
            que.push(x);
        }

        else if(s=="pop"){
            if(que.empty()) cout<<-1<<'\n';
            else{
                cout<<que.front()<<'\n';
                que.pop();
            }
        }
        
        else if(s=="size"){
            cout<<que.size()<<'\n';
        }
        else if(s=="empty"){
            cout<<que.empty()<<'\n';
        }
        else if(s=="front"){
            if(que.empty()) cout<<-1<<'\n';
            else cout<<que.front()<<'\n';
        }
        else if(s=="back"){
            if(que.empty()) cout<<-1<<'\n';
            else cout<<que.back()<<'\n';
        }
        


    }
    



    return 0;
}