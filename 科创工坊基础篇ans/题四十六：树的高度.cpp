//ֻͨ��50%case����ҿ��Ż�һ���㷨 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<vector<int>> v;//����һ�������������� 
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
    for(i=0;i<n;i++) v.push_back(vector<int>()); //��������Ԫ�� 
    vector<bool> root(n,false); //�������ڵ������־ 
    for(i=0;i<n-1;i++)
	{
        cin>>F>>T;
        root[T]=true;//Ϊÿһ���ҵ����ӽڵ���true 
        v[F].push_back(T);//ÿһ�ڵ�����Ӧ���ӽڵ��� 
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
