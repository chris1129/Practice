//
//  MyLinkedlist.h
//  implement a queue
//
//  Created by Sheng-Yung Cheng on 4/20/18.
//  Copyright © 2018 Sheng-Yung Cheng. All rights reserved.
//

#ifndef MyLinkedlist_h
#define MyLinkedlist_h

template <class T>
struct mynode{
    
    mynode<T>* next;
    T data;
};

template <class T>
class mylinkedlist {
public:
    mylinkedlist(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    void push_back(T val){
        mynode<T>* nd=new mynode<T>;
        nd->data=val;
        nd->next=NULL;
        if(!head&&!tail){
            head=nd;tail=nd;
            size++;
            return ;
        }
        tail->next=nd;
        tail=tail->next;
        size++;
    }
    void push_front(T val){
        mynode<T>* nd=new mynode<T>;
        nd->data=val;
        nd->next=NULL;
        mynode<T>* temp=nd;
        temp->next=head;
        head=temp;
        size++;
    }
    bool pop_front(){
        if(!head&&!tail)return false;
        mynode<T>* temp;
        temp=head;
        head=head->next;
        delete(temp);
        size--;
        return true;
    }
    bool pop_back(){
        if(!head&&!tail)return false;
        if(head==tail){
            return pop_front();
        }
        mynode<T>* temp;
        temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        tail=temp;
        delete(temp);
        size--;
        return true;
    }
    bool isempty(){
        return size==0;
    }
    int get_size(){
        return size;
    }
    void print(){};
    T getfront(){
        return head->data;
    }
    T getend(){
        return tail->data;
    }
private:
    mynode<T>* head;
    mynode<T>* tail;
    int size;
};



#endif /* MyLinkedlist_h */
