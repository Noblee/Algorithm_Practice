//
// Created by Noble on 22/02/2018.
//
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string rev(string str)
{
    string temp;
    int flag=0;
    for(int i =str.size()-1;i>=0;i--)
    {
        if(str[i]=='0'&&flag==0) {

        }
        else
        {
            temp.push_back(str[i]);
            flag=1;
        }
    }
    return temp;
}
int con(string str)
{
    int a;
    sscanf(str.c_str(),"%d",&a);
            return a;
}
string conz(int a)
{
    char str[100];
    sprintf(str,"%d",a);
    string az(str);
    return az;
}
int main()
{
    string a,b;
    cin>>a>>b;
    int z= con(rev(conz(con(rev(a)) + con(rev(b)))));
    cout<<z;
    return 0;
}