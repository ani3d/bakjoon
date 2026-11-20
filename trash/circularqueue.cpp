#include <iostream>
#include <algorithm>

using namespace std;

#define Size 8

char queue[Size];
int front=0;
int rear=0;

void insertQ(char data){
    rear=(rear+1)%Size;
    if(front==rear){
        cout<<"Queue full\n";
        exit(0);
    }
    queue[rear]=data;
}

char deleteQ(){
    if(front==rear){
        cout<<"Queue empty\n";
        exit(0);
    }
    front=(front+1)%Size;
    return(queue[front]);
}

void printQ(){
    int i;

    if(front!=rear){
        i=front;
        do{
            i=(i+1)%Size;
            cout<<queue[i]<<"->";
        }while(i!=rear);
        cout<<'\n';
    }
}

int main(){
    char val;

    insertQ('A');
    insertQ('B');
    insertQ('C');
    insertQ('D');
    
    printQ();
    insertQ('F');
    printQ();
    val=deleteQ();
    printQ();





    return 0;
}