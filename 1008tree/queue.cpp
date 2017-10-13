#include <stdio.h>
#include <malloc.h>
#include "queue.h"
#define MAXSIZE 20
void init_squeue(sq_queue *q)
{
	q->front = 0;
	q->rear = 0;
}
int lenth_squeue(sq_queue *q)
{
	int len = ((q->rear) + MAXSIZE - (q->front)) % MAXSIZE;
	return len;
}
bool in_squeue(sq_queue *q, tree *val)
{
	//插入时 先判断队满
	if ((q->rear + 1) % MAXSIZE == q->front)
	{
		printf("队满！\n");
		return false;
	}
	q->data[q->rear] = val;
	q->rear = (q->rear + 1) % MAXSIZE;
	//队列只允许尾插       循环队列允许 尾指针<头指针    解决假溢出现象   
	return true;
}
tree * out_squeue(sq_queue *q)
{
	//删除前 先判断队空
	if (q->rear == q->front)
	{
		printf("队空！\n");
		return false;
	}
	tree *temp = (tree*)malloc(sizeof(tree));
	temp = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return  temp;//删除在头删
}



