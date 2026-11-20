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
    int n,m;
    cin>>n>>m;
    vector<int> lec;
    for(int i=0;i<m;i++){
        int temp;
        cin>>temp;
        lec.push_back(temp);
    }
    //학점순으로 정렬 + 그리디

    int st=0;
    int sum=0;
    map<int,int> index;
    

    return 0;   
}