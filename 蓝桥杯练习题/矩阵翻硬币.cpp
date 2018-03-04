//
// Created by Noble on 22/02/2018.
//
#include <iostream>
#include <cmath>
using namespace std;
//此题为JAVA组的，C++需要大数库
int main()
{
    unsigned long long a,b,aa,bb;
    cin>>a>>b;
    aa=(unsigned long long)sqrtl(a);
    bb=(unsigned long long)sqrtl(b);
    cout<<aa*bb;
    return 0;
}