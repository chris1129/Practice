//
//  main.cpp
//  Reservoir Sampling
//
//  Created by Sheng-Yung Cheng on 4/24/18.
//  Copyright © 2018 Sheng-Yung Cheng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
void ReservoirSampling(vector<int>&stream,int k){
    vector<int>Reservoir;
    for(int i=0;i<k;i++){
        Reservoir.push_back(stream[i]);
    }
    for(int i=k;i<stream.size();i++){
        int j=rand()%(i+1);//pick one num from 0~i
        if(j<k){
            Reservoir[j]=stream[i];
        }
    }
    cout<<"Selected:";
    for(auto r:Reservoir){
        cout<<r<<",";
    }
    
}
//Proof:
//arr=1,2,3,4....,n
//For num in initial Reservoir(size 4):
//The prob of number 1(inside the initial Reservoir) in the final Reservoir= (4/5)*(5/6)*(6/7)...*((n-1)/n)=(4/n)
//The prob of num 5 (outside the initial Reservoir) in the final Reservoir=(4/5)*(5/6)*...((n-1)/n)=(4/n)
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int>input={1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    ReservoirSampling(input,5);
    return 0;
}
