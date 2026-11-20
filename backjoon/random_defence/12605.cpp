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

    int n;
    cin>>n;
    cin.ignore();
    string token;

    for(int i=1;i<=n;i++){
        string word;
        stack<string> s;
        getline(cin,word);

        stringstream sstream(word);
        while(getline(sstream,token,' ')) s.push(token);

        cout<<"Case #"<<i<<": ";
        while(!s.empty()){
            token=s.top();
            s.pop();
            cout<<token<<' ';
        }
        cout<<'\n';




    }





    return 0;
}