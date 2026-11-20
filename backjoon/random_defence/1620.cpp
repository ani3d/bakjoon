#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<sstream>
using namespace std;


map<string,int> pokemon;
string name[100001];
int n,m;
string temp;
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>temp;
        name[i]=temp;
        pokemon.insert(make_pair(temp,i));
    }

    for(int i=1;i<=m;i++){
        cin>>temp;
        if(isdigit(temp[0])){
            cout<<name[stoi(temp)]<<'\n';
        }
        else{
            cout<<pokemon.find(temp)->second<<'\n';
        }
    }
    





    return 0;
}