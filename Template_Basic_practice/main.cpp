//
//  main.cpp
//  Template_practice
//
//  Created by Sheng-Yung Cheng on 4/7/18.
//  Copyright © 2018 Sheng-Yung Cheng. All rights reserved.
//

#include <iostream>
using namespace std;

class myclass{
public:
    myclass(int v):val(v){};
    
    //copy constructor which support operater mc1=mc2
    myclass(const myclass &mc2) {val=mc2.val; }
    
    //default constructor which don't take any parameter
    myclass(){}
    
    //operator overload
    myclass operator+(myclass b){
        myclass ret(this->val+b.val);
        return ret;
    }
    bool operator<(myclass b){
        if(val<b.val)return true;
        return false;
    }
    bool operator>(myclass b){
        if(val<b.val)return false;
        return true;
    }
    int val;
};

//operator << overload
ostream& operator<<(ostream& os,const myclass& c){//this should not be a member function of myclass
    os<<c.val;
    return os;
}

//made a template class that can add different type of class
template <class T>//This line is a key word to let T be a generic class
T addcrap(T a,T b){
    return a+b;
}

//class template
template<class T>
class Bucky{
public:
    T first,second;
    Bucky(T a,T b){
        first=a;
        second=b;
    }
    T bigger();
};

template<class TT>
TT Bucky<TT>::bigger(){//let bucky know TT is the same with T
    if(first>second)return first;
    return second;
}

//template specialization:EX: we want constructor only take char
template <class T>
class spucky {
    
public:
    spucky(T a){
        cout<<a<<" is not a char"<<endl;
    }
};

template <>
class spucky<char>{
public:
    spucky(char p){
        cout<<p<<" is a char"<<endl;
    }
};

int main(int argc, const char * argv[]) {
    myclass c(10);
    myclass b(11);
    
    ////////function template:
    cout<<addcrap(c, b)<<endl;
    
    ////////class template:
    Bucky<myclass> bky(c,b);
    cout<<bky.bigger()<<endl;
    
    ////////template sepcialization:
    spucky<myclass> s1(c);
    spucky<int> s2(22);
    spucky<char> s3('q');
    return 0;
}
