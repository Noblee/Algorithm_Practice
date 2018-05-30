#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>

using namespace std;
int rel[100005];
struct Node
{
    int num ,magnify;
};
vector<Node> ans;
int main() {
    int n;
    double r_start, reduce;
    cin >> n >> r_start >> reduce;
    reduce =reduce/100;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num != 0) {
            for (int j = 0; j < num; j++) {
                int temp;
                cin>>temp;
                rel[temp]=i;
            }
        } else {
            int temp;
            cin>>temp;
            Node node;
            node.magnify=temp;
            node.num=i;
            ans.push_back(node);
        }
    }
    double sum = 0;
    for (int i = 0; i < ans.size(); i++) {

        int counts;
        int p=ans[i].num;
        if(rel[p]==0)
            counts=0;
        else
            counts=1;
        while(1)
        {
            if(rel[p]!=0)
                counts++;
            else
                break;
            p=rel[p];
        }
        sum+=ans[i].magnify*r_start*pow(1-reduce,counts);
    }
    printf("%d",(int)sum);
    return 0;
}