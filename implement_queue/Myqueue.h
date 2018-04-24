//
//  Myqueue.h
//  implement a queue
//
//  Created by Sheng-Yung Cheng on 4/20/18.
//  Copyright © 2018 Sheng-Yung Cheng. All rights reserved.
//

#ifndef Myqueue_h
#define Myqueue_h
#include "MyLinkedlist.h"
template<class T>
class myqueue{
public:
    myqueue(){}
    void push(T a){
        lst.push_back(a);
    }
    void pop(){
        lst.pop_front();
    }
    T front(){
        return lst.getfront();
    }
    bool isempty(){
        return lst.isempty();
    }
private:
    mylinkedlist<T>lst;
    
    
};
#endif /* Myqueue_h */
