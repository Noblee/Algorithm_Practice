#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;
struct Node {
    string name;
    int num;
    set<int> zan;
};
vector<Node> data;
bool compare(Node &a,Node &b)
{
    if(a.zan.size()!=b.zan.size())
        return a.zan.size()>b.zan.size();
    else
    {
        return a.num<b.num;
    }
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        data.push_back(Node());
        cin >> data.back().name >> data.back().num;
        for(int i =0;i<data.back().num;i++)
        {
            int zz;
            cin>>zz;
            data.back().zan.insert(zz);
        }
    }
    sort(data.begin(),data.end(),compare);
    int i = 0;
    for(;i<3&&i<data.size();i++)
    {
        if(i!=2)
        cout<<data[i].name<<" ";
        else
            cout<<data[i].name;
    }
    for(;i<3;i++)
    {
        if(i!=2)
        cout<<"- ";
        else
            cout<<"-";
    }
    return 0;
}