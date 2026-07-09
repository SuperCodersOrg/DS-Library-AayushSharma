#include<iostream>
#include "Vector.h"
using namespace std ;
int main(){
Vector<int>v;
// v.push_back(1);
// v.push_back(2);
for(int i=0;i<v.Size();i++){
    cout<<v[i];
}
return 0;
}