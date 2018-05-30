#include<iostream>
#include<algorithm>
using namespace std;
int sort(int arr[],int low, int top)
{
	int a = low, b = top;
	int buff = arr[low];
	while(a<b){
		while(arr[b] >= buff && a < b) b--;
		while(arr[a] <= buff && a < b) a++;
		swap(arr[a], arr[b]);
	}
	//由于b先行，所以b所停位置必然小于buff
    //或者停在a处（a所停位置一定小于buff）
    //故此处跟a和low做交换
	arr[low] = arr[a];
    arr[a] = buff;
	return a;
}
void partition(int arr[],int low,int top)
{
	if(low>top)
		return;
	int mid = sort(arr,low,top);
	partition(arr,low,mid-1);
	partition(arr,mid+1,top);
	return;
}
int main()
{
	int a[]={53,122,21,2323,31231,31313,213,11};
    partition(a,0,7);
    for (int i = 0; i <8; ++i)
    {
    	cout<<a[i]<<endl;
    }
	return 0;
}