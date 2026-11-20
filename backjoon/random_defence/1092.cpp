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
    int n;
    cin>>n;
    vector<int> crain;
    int m;
    
    vector<int> box;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        crain.push_back(temp);
    }
    cin>>m;
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        box.push_back(temp);
    }
    sort(crain.begin(),crain.end());
    sort(box.begin(),box.end());
    if(crain.back()<box.back()){
        cout<<-1<<'\n';
        return 0;

    }
    int time=0;
    int movecnt=0;
    while(!box.empty()){
        time++;
        for(int i=crain.size()-1;i>=0;i--){
            for(int j=box.size()-1;j>=0;j--){
                if(crain[i]>=box[j]){
                    box.erase(box.begin()+j);
                    break;
                }
            }
        }
        

    }
    

    cout<<time;



    return 0;   
}