#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int n;
    char game;
    cin>>n>>game;
    set<string> member;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;
        member.insert(name);
    }
    int player=-1;
    if(game=='Y'){
        player=1;
    }
    else if(game=='F'){
        player=2;
    }
    else {
        player=3;
    }
    int cnt=0;
    int play=0;
    
    for(int i=0;i<member.size();i++){
        cnt++;
        if(cnt==player){
            play++;
            cnt=0;
        }
    }
    cout<<play;





    return 0;
}