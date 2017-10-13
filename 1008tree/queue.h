#ifndef QUEUE_H
#define QUEUE_H


#include "tree.h"
#define MAX 20
typedef struct{
	tree * data[MAX];
	int front;//Õ∑÷∏’Î
	int rear;
}sq_queue;

void init_squeue(sq_queue *q);
int lenth_squeue(sq_queue *q);
bool in_squeue(sq_queue *q, tree *val);
tree * out_squeue(sq_queue *q);

#endif