//
//  hashTable.h
//  implementHashTable
//
//  Created by Sheng-Yung Cheng on 4/23/18.
//  Copyright © 2018 Sheng-Yung Cheng. All rights reserved.
//


#ifndef hashTable_h
#define hashTable_h
#include <iostream>
using namespace std;
class hashunit{
public:
    hashunit(int key,int val){
        this->key=key;
        this->val=val;
    }
    int getkey(){
        return this->key;
    }
    int getval(){
        return this->val;
    }
private:
    int key;
    int val;
    
};
class hashTable{
    
public:
    const int table_size=128;//limit the tablesize to 128
    hashTable(){
        table= new hashunit*[table_size];
        for(int i=0;i<table_size;i++){
            table[i]=NULL;
        }
    }
    int get(int key){
        int hash=key%table_size;
        //if(hashunit[hash]==NULL)return -1;
        while(table[hash]!=NULL&&table[hash]->getkey()!=key){
            hash=(hash+1)%table_size;
        }
        if(table[hash]==NULL)return -1;
        return table[hash]->getval();
    }
    void put(int key,int val){
        int hash=key%table_size;
        if(table[hash]==NULL){
            table[hash]=new hashunit(key,val);
            return ;
        }
        while(table[hash]!=NULL&&table[hash]->getkey()!=key){
            //hashunit[hash]->getkey()!=key =>This is used to avoid duplicated key  ex put(1,2)  put(1,5)
            hash=(hash+1)%table_size;
            
        }
        if(table[hash]!=NULL){//means this pos already have unit with the same key
            delete table[hash];
            
        }
        table[hash]=new hashunit(key,val);
        
    }
    void remove(int key){
        
        int hash=key%table_size;
        if(table[hash]==NULL)return ;
        while(table[hash]!=NULL&&table[hash]->getkey()!=key){
            hash=(hash+1)%table_size;
        }
        
        
        if(table[hash]!=NULL){
            
            delete table[hash];
            table[hash]=NULL;
        }
        
    }
    
    
private:
    
    hashunit** table;
    //a table array, each element contains a pointer pointing to a hashunit
    
};

#endif /* hashTable_h */
