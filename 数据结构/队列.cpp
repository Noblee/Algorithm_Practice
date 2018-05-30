#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#define ERRO 0xffffffff
using namespace std;
typedef int DataType;
#define maxSize 1000
struct SNode
{
	DataType data;
	SNode * next;
} ;
struct LiQueue
{
	SNode * front;
	SNode * rear;
};
void init(LiQueue * &L)
{
	L  = (LiQueue *)malloc(sizeof(LiQueue));
	L->front = L->rear = NULL;
}
DataType top(LiQueue *L)
{
	if (!(L == NULL || L->front == NULL))
		return L->front->data;
	return ERRO;
}
bool push(LiQueue *L, DataType val)
{
	if (L == NULL)
		return false;
	SNode * r = (SNode *)malloc (sizeof(SNode));
	r->data = val;
	r->next = NULL;
	if (L->rear == NULL)
		L->rear = L->front = r;
	else {
		L->rear->next = r;
		L->rear = r;
	}
	return true;
}
bool pop(LiQueue *L, DataType &val)
{
	if (L->rear == NULL || L == NULL)
		return false;
	SNode * p = L->front;

	val = L->front->data;
	L->front = L->front->next;
	if (L->front == NULL)
		L->rear  = NULL;
	free(p);
	return true;
}
void print(SNode *L)
{
	printf("[");
	SNode * r = L;
	while (r->next != NULL)
	{
		r = r->next;
		printf("%2d", r->data);
		if (r->next)
			printf(",");
	}
	printf("]\n");
}
int main()
{

	LiQueue * L;
	init(L);
	printf("输入要执行函数的序号\n1.push\n2.pop\n");
	DataType temp;
	while (cin >> temp)
	{
		if (temp == 1)
		{
			printf("请输入push的元素");
			cin >> temp;
			if (push(L, temp)) printf("push成功");
			else printf("push失败\n");
			if (top(L) != ERRO)
				printf("，当前队列头为%d\n", top(L));
			else
				printf("，当前队列头为空\n");


		}
		else
		{
			if (pop(L, temp)) printf("pop成功，出队列元素为%d", temp);
			else printf("pop失败");
			if (top(L) != ERRO)
				printf("，当前队列头为%d\n", top(L));
			else
				printf("，当前队列头为空\n");
		}
	}
	return 0;
}

