#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int n; cin>>n;
    int kbs1;
    int kbs2;
    vector<string> ch;
    for(int i=0;i<n;i++){
        string name;
        cin>>name;

        if(name=="KBS1"){
            kbs1=i;
        }
        if(name=="KBS2"){
            kbs2=i;
        }
        ch.push_back(name);
    }

   
    
    for(int i=0;i<kbs1;i++){
        cout<<1;
    }
    for(int i=0;i<kbs1;i++){
        cout<<4;
    }
    if(kbs1>kbs2){
        kbs2++;
    }
    for(int i=0;i<kbs2;i++){
        cout<<1;
    }
    for(int i=0;i<kbs2-1;i++){
        cout<<4;
    }


    return 0;
}