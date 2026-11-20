#include<iostream>
#include<vector>

using namespace std;
struct Player{
    int level;
    string name;

};
vector<int> cnt;
bool visit[301];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    vector<Player> player;
    vector<vector<Player>> room;
    int p,m; cin>>p>>m;
    for(int i=0;i<p;i++){
        int l;string n; cin>>l>>n;
        player.push_back({l,n});
    }
    room[0].push_back({player[0].level,player[0].name});
    
    cnt[0]=1;
    int sidx=0;

    for(int i=sidx;i<room.size();i++){
        for(int j=1;i<player.size();i++){
            if(visit[j]) continue;
            

        }

    }

    return 0;
}