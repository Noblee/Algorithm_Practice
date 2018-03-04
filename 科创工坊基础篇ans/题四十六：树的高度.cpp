//只通过50%case，大家可优化一下算法 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> v;//建立一个二叉树向量组 
int fun(int p) 
{
    int count=0;
    for(int i=0;i<v[p].size();i++) count=max(count,fun(v[p][i]));
    return count+1;
}

int main() 
{
    int n,i,F,T;
    cin>>n;
    for(i=0;i<n;i++) v.push_back(vector<int>()); //创建向量元素 
    vector<bool> root(n,false); //二叉树节点遍历标志 
    for(i=0;i<n-1;i++)
	{
        cin>>F>>T;
        root[T]=true;//为每一个找到的子节点标记true 
        v[F].push_back(T);//每一节点插入对应的子节点编号 
    }
    for(i=0;i<n;i++)
	{
        if(!root[i]) 
		{
            cout<<fun(i);
            break;
        }
    }
    return 0;
}
