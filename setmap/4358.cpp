#include <iostream>
#include <string.h>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<sstream>
#include<map>
#include<iomanip>

using namespace std;

vector<string> v;

 map<string,int> tree_cnt;



int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);
    string temp;
    int cnt=0;
    double per;
    while(getline(cin,temp)){
        v.push_back(temp);
        cnt++;
    }
    sort(v.begin(),v.end());

    for(int i=0;i<v.size();i++){
       tree_cnt[v[i]]++;
    }

    for(auto& pair:tree_cnt){
        per=(pair.second/(double)cnt)*100;
        
        cout<<pair.first<<" "<<fixed<<setprecision(4)<<per<<'\n';
    }

    



    return 0;
}