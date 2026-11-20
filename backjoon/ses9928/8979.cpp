#include<iostream>
#include<vector>

using namespace std;

struct medal{
    int gold;
    int silver;
    int bronze;
    int score;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    vector<medal> co(n+1);
    int num;
    for(int i=0;i<n;i++){
        cin>>num;
        cin>>co[num].gold>>co[num].silver>>co[num].bronze;
        co[num].score=1;
    }
   
    
    for(int i=1;i<=n;i++){
        if(i==k) continue;
        if(co[i].gold>co[k].gold){
            co[k].score+=1;
        }
        else if(co[i].gold==co[k].gold){
            if(co[i].silver>co[k].silver){
                co[k].score+=1;
            }
            else if(co[i].silver==co[k].silver){
                if(co[i].bronze>co[k].bronze){
                    co[k].score+=1;
                }
            }
        }
    }
        
    cout<<co[k].score;


    return 0;
}