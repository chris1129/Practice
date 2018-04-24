//
//  main.cpp
//  RandMax
//
//  Created by Sheng-Yung Cheng on 4/24/18.
//  Copyright © 2018 Sheng-Yung Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int randmax(vector<int>arr){
    
    int count=0;int max=INT_MIN;int ret=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]>max){
            ret=i;
            max=arr[i];
            count=1;
        }else if(arr[i]==max){
            count++;
            int j=rand()%count;
            if(j==0){
                ret=i;
            }
        }
    }
    
    return ret;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int>arr={3,10,2,10,5,10,10,5};
    cout<<randmax(arr);
    cout<<randmax(arr);
    cout<<randmax(arr);
    cout<<randmax(arr);
    return 0;
}
