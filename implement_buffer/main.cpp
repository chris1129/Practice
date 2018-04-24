//
//  main.cpp
//  implement_buffer
//
//  Created by Sheng-Yung Cheng on 4/9/18.
//  Copyright © 2018 Sheng-Yung Cheng. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;
class Myclass{
public:
    Myclass(int s){
        head=new int[s];
        end=head;
        size=s;
        fnt=head;
        capacity=s;
        bound=head;
        for(int i=0;i<s;i++){
            bound++;
        }
    }
    void push(int x){
        cout<<"call push"<<endl;
        if((end-fnt)==capacity){
            cout<<"fuull"<<endl;
            return ;
        }
        if(end==bound){
            update();
        }
        
        *end++=x;
        
        
    }
    void update(){
        cout<<"call update"<<endl;
        
        int* temphead=new int[size];
        int* curr=temphead;
        while(fnt!=end){
            *curr=*fnt;
            curr++;
            fnt++;
        }//copy value
        end=curr;
        head=temphead;
        fnt=head;
        bound=head;
        for(int i=0;i<size;i++){
            bound++;
        }
    }
    int front(){
        if(fnt>=end)return -1;
        return *fnt;
    }
    void pop(){
        if(fnt>=end)return ;
        fnt++;
        
    }
private:
    int* end;
    int* head;
    int size;
    int *fnt;
    int* bound;
    int capacity;
};
void move(char* buf){
    buf++;
}
int main()
{
//    Myclass myclass (3);
//    myclass.push(1);
//    myclass.push(2);
//    myclass.push(3);
//    myclass.push(4);
//    cout<<myclass.front()<<endl;
//    myclass.pop();
//    cout<<myclass.front()<<endl;
//    myclass.pop();
//    cout<<myclass.front()<<endl;
//    myclass.pop();
//    cout<<myclass.front()<<endl;
//    myclass.pop();
//    myclass.push(4);
//    cout<<myclass.front()<<endl;
//    myclass.pop();

    char* p="abcd";
    move(p);
    cout<<*p;
    
    return 0;
}


