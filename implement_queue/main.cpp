//
//  main.cpp
//  implement a queue
//
//  Created by Sheng-Yung Cheng on 4/20/18.
//  Copyright © 2018 Sheng-Yung Cheng. All rights reserved.
//

#include <iostream>
#include "Myqueue.h"
#include "MyLinkedlist.h"
using namespace std;


struct Myclass{
    int val;
};
int main(int argc, const char * argv[]) {

    myqueue<Myclass>q;
    for(int i=0;i<5;i++){
        Myclass temp;
        temp.val=i;
        q.push(temp);
    }
    while(!q.isempty()){
        Myclass myclass=q.front();
        cout<<myclass.val<<endl;
        q.pop();
    }



    
    
    return 0;
}
