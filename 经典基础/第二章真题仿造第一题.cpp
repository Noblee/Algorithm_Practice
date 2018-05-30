#include <stdio.h>

void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void merge (int a[],int m,int n)
{
	int *b = (int *)malloc((m+n)*sizeof(int));
	int p=0 ,q=m;
	int i=0;
	while(p<m&&q<m+n)
	{
		if(a[p]<a[q])
			b[i++]=a[p++];
		else
			b[i++]=b[q++];
	}
	while(p<m)b[i++]=a[p++];
	while(q<m+n)b[i++]=a[q++];
	for(int i =0;i<m+n-1;i++)
		printf("%d, ", b[i]);
}
int main()
{
	int a[]={0,1,4,6,7,3,5,9};
	merge(a,5,3);
	for(int i =0;i<8;i++)
		printf("%d, ", a[i]);
	return 0;
}