//
// Created by Noble on 06/05/2018.
//
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
   int a[]={8,1,6,6};
   std::vector<int> v(4);
           for(int i =0;i<4;i++)
            v[i]=a[i];
    sort(v.begin(),v.end());
    do{
        for(int i =0;i<4;i++)
            cout<<v[i]<<" ";
        cout<<endl;

    }while(next_permutation(v.begin(),v.end()));

    return 0;
}
