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
    
    

    int t;
    cin>>t;
    
    while(t--){
        long double s;
        vector<long double> arr[4];
        vector<long double> b;
        
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                cin>>s;
                arr[i].push_back(s);
            }
            cin>>s;
            b.push_back(s);
        }
            
        
        

        long double det;
        det=arr[0][0]*(arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1])-arr[0][1]*(arr[1][0]*arr[2][2]-arr[1][2]*arr[2][0])+arr[0][2]*(arr[1][0]*arr[2][1]-arr[1][1]*arr[2][0]);
        long double deta[3];
        deta[0]=b[0]*(arr[1][1]*arr[2][2]-arr[1][2]*arr[2][1])-arr[0][1]*(b[1]*arr[2][2]-arr[1][2]*b[2])+arr[0][2]*(b[1]*arr[2][1]-arr[1][1]*b[2]);
        deta[1]=arr[0][0]*(b[1]*arr[2][2]-arr[1][2]*b[2])-b[0]*(arr[1][0]*arr[2][2]-arr[1][2]*arr[2][0])+arr[0][2]*(arr[1][0]*b[2]-b[1]*arr[2][0]);
        deta[2]=arr[0][0]*(arr[1][1]*b[2]-b[1]*arr[2][1])-arr[0][1]*(arr[1][0]*b[2]-b[1]*arr[2][0])+b[0]*(arr[1][0]*arr[2][1]-arr[1][1]*arr[2][0]);
        for(int i=0;i<3;i++){
            
            cout<<deta[i]<<' ';
        }
        cout<<det<<'\n';
        if(det==0){
            cout<<"No unique solution\n\n";
            continue;
        }
        long double ans[3];
        for(int i=0;i<3;i++){
            ans[i]=deta[i]/det;
            if(ans[i]==0.0) ans[i]=abs(ans[i]);
        }
        cout<<"Unique solution: ";
        for(int i=0;i<3;i++){
            cout<<fixed;
            cout.precision(3);
            cout<<ans[i]<<' ';
            cout.precision(0);
        }
        cout<<'\n'<<'\n';
    }


    return 0;   
}