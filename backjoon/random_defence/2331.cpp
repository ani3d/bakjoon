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

vector<int> v;
int arr[5000000];
int main(){
    ios::sync_with_stdio(0);// 
    cin.tie(0);

    
    
    int a,p;
    cin>>a>>p;
    v.push_back(a);
    arr[a]++;
    
    while(1){
        int sum=0;
        if(arr[a]==2) break;
        string temp=to_string(a);
        for(int i=0;i<temp.size();i++){
            sum+=pow(temp[i]-'0',p);
        }
        a=sum;
        v.push_back(a);
        arr[a]++;
        
    }

    int count=0;
    for(int i=0;i<v.size();i++){
        if(v[i]==a) break;
        count++;
    }
    cout<<count;


    return 0;
}