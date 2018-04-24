//
//  main.cpp
//  implementHashTable
//
//  Created by Sheng-Yung Cheng on 4/23/18.
//  Copyright © 2018 Sheng-Yung Cheng. All rights reserved.
//

#include <iostream>

#include "hashTable.h"
#include "HashTable_Linkedlist.h"
using namespace std;
int main(int argc, const char * argv[]) {
    
    hashmap hash(128);
    hash.put(0, 5);
    hash.put(128,3);
    hash.remove(128);
    cout<<hash.get(128)<<endl;
    cout<<hash.get(0)<<endl;
    cout<<hash.get(4)<<endl;

    
    return 0;
}
