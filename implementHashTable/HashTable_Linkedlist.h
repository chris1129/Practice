//
//  HashTable_Linkedlist.h
//  implementHashTable
//
//  Created by Sheng-Yung Cheng on 4/23/18.
//  Copyright © 2018 Sheng-Yung Cheng. All rights reserved.
//

#ifndef HashTable_Linkedlist_h
#define HashTable_Linkedlist_h
#include<vector>
#include<list>
class hashnode{
public:
    hashnode(int k,int v){
        this->key=k;
        this->val=v;
    }
    int getKey(){
        return key;
    }
    int getVal(){
        return val;
    }
    void setval(int v){
        val=v;
    }
private:
    int key;
    int val;
    
};
class hashmap{
    
public:
    hashmap(int s){
        tablesize=s;
        table.resize(tablesize);
    }
    int get(int key){
        int idx=gethash(key);
        auto& bucket=table[idx];
        for(auto it=bucket.begin();it!=bucket.end();it++){
            if(it->getKey()==key){
                return it->getVal();
            }
        }
        
        
        
        return -1;
    }
    void put(int key,int val){
        int idx=gethash(key);
        auto& bucket=table[idx];
        
        for(auto it=bucket.begin();it!=bucket.end();it++){
            if(it->getKey()==key){
                //find a exist key
                it->setval(val);
                return ;
            }
        }
        //Key doesn't exist, create a new key,val pair
        bucket.push_back(hashnode(key,val));
        
        
    }
    void remove(int key){
        int idx=gethash(key);
        auto& bucket=table[idx];
        for(auto it=bucket.begin();it!=bucket.end();it++){
            if(it->getKey()==key){
                //find a exist key
                bucket.erase(it);
                return ;
            }
        }
    }
    int gethash(int key){
        return key%tablesize;
    }
private:
    vector<list<hashnode>>table;
    int tablesize;
};

#endif /* HashTable_Linkedlist_h */
