#include<cstdio>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<cmath>

using namespace std;
int rel[100000];
vector<int> ans;
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
            rel[temp]=i;
            ans.push_back(i);
        }
    }
    double sum = 0;
    for (int i = 0; i < ans.size(); i++) {
        int counts=1;
        int p=ans[i];

        while(1)
        {
            if(rel[p]!=0)
                counts++;
            else
                break;
            p=rel[p];
        }
        sum+=rel[ans[i]]*r_start*pow(1-reduce,counts);
    }
    printf("%lf",sum);
    return 0;
}