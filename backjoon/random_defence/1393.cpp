#include<iostream>
#include<vector>

using namespace std;

int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    int x,y;
    cin>>x>>y;
    int nx,ny,dx,dy;
    cin>>nx>>ny>>dx>>dy;
    int Gcd;
    if(abs(dx)>abs(dy)){
        Gcd=gcd(abs(dx),abs(dy));
    }
    else{
        Gcd=gcd(abs(dy),abs(dx));
    }
    
    dx=dx/Gcd;
    dy=dy/Gcd;
    int dist=(nx-x)*(nx-x)+((ny-y)*(ny-y));
    

    if(x>nx){
        while(1){
            int temp;
            nx+=dx;
            ny+=dy;
            temp=(nx-x)*(nx-x)+(ny-y)*(ny-y);
            if(temp<dist){
                dist=temp;
            }
            else{
                cout<<nx-dx<<' '<<ny-dy;
                return 0;
            }
        }
    }
    else{
        while(1){

            int temp;
            nx-=dx;
            ny-=dy;
            temp=(nx-x)*(nx-x)+(ny-y)*(ny-y);
            if(temp<dist){
                dist=temp;
            }
            else{
                cout<<nx+dx<<' '<<ny+dy;
                return 0;
            }
        }

    }
    
    






    
    return 0;
}