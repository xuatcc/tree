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
	//����ʱ ���ж϶���
	if ((q->rear + 1) % MAXSIZE == q->front)
	{
		printf("������\n");
		return false;
	}
	q->data[q->rear] = val;
	q->rear = (q->rear + 1) % MAXSIZE;
	//����ֻ����β��       ѭ���������� βָ��<ͷָ��    ������������   
	return true;
}
tree * out_squeue(sq_queue *q)
{
	//ɾ��ǰ ���ж϶ӿ�
	if (q->rear == q->front)
	{
		printf("�ӿգ�\n");
		return false;
	}
	tree *temp = (tree*)malloc(sizeof(tree));
	temp = q->data[q->front];
	q->front = (q->front + 1) % MAXSIZE;
	return  temp;//ɾ����ͷɾ
}



