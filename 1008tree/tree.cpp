
#include "queue.h"
#include <stdio.h>
#include<malloc.h>
#include <stdlib.h>


tree *make_root(elemtype x)
{
	tree *root = (tree*)malloc(sizeof(tree));
	root->data = x;
	root->brother = NULL;
	root->firstchild = NULL;
	return root;
}
tree *insert_child(tree *ptr, elemtype x)
{
	if (ptr == NULL)
		return NULL;
	tree *child = (tree *)malloc(sizeof(tree));
	child->data = x;
	if (ptr->firstchild == NULL)
	{
		ptr->firstchild = child;
	}
	else
	{
		ptr = ptr->firstchild;
		while (ptr->brother != NULL)
		{
			ptr = ptr->brother;
		}
		ptr->brother = child;
	}
	child->brother = NULL;
	child->firstchild = NULL;
	return child;
}
tree *insert_brother(tree *ptr, elemtype x)
{
	if (ptr == NULL)
		return NULL;
	tree *brother = (tree *)malloc(sizeof(tree));
	brother->data = x;
	while (ptr->brother != NULL)
	{
		ptr = ptr->brother;
	}
	ptr->brother = brother;
	brother->brother = NULL;
	brother->firstchild = NULL;
	return brother;
}
tree *find_value(tree *ptr, elemtype x)
{
	if (ptr == NULL || ptr->data == x)
		return ptr;
	else
	{
		tree *res = NULL;
		ptr = ptr->firstchild;
		while ((ptr != NULL) && ((res = find_value(ptr, x)) == NULL))
		{
			ptr = ptr->brother;
		}
		return res;
	}
}
tree *find_parent(tree *ptr, tree *child)
{
	if (child == NULL || ptr == NULL || ptr == child)
		return NULL;
	else
		return parent(ptr, child);
}
tree *parent(tree *ptr, tree *child)
{
	if (ptr == NULL)
		return ptr;
	tree *p = ptr->firstchild;
	tree *res = NULL;
	while (p != NULL && p != child )
	{
		res = parent(p, child);
		if (res != NULL)
			return res;
		p = p->brother;
	}
	if (p != NULL)
	{
		return ptr;
	}
	else
		return NULL;
		
}
int size_tree(tree *ptr,int *count)  //统计数的结点个数
{
	if (ptr == NULL)
		return 0;
	ptr = ptr->firstchild;
	*count += 1;  //根节点
	if (ptr == NULL)
	{
		return *count;
	}	
	while (ptr!=NULL)
	{
		size_tree(ptr,count);
		ptr = ptr->brother;
	}
	return *count;
}
void make(tree *ptr, list_tree *list_ptr, int list_ptr_index,int *list_index)
{
	//list_ptr->data = ptr->data; //数组
	ptr = ptr->firstchild;
	if (ptr == NULL)
	{
		return ;
	}
	*list_index += 1;
	list_ptr[*list_index].data = ptr->data;
	list_ptr[*list_index].parent = list_ptr_index;
	
	if (ptr->firstchild != NULL)
	{
		make(ptr, list_ptr, *list_index, list_index);
	}

	while (ptr->brother != NULL)
	{
		ptr = ptr->brother;
		*list_index += 1;
		list_ptr[*list_index].data = ptr->data;
		list_ptr[*list_index].parent = list_ptr_index;
		make(ptr, list_ptr, *list_index, list_index);
		//其中list_ptr - list_root   代表下标
	}
}
list_tree *make_listtree(tree *root, int count)
{
	//根据链式的树创建  顺序结构的树
	list_tree *list_root = (list_tree*)calloc(count, sizeof(list_tree));

	list_root->data = root->data;
	list_root->parent = -1;
	int index = 0;
	make(root, list_root, 0,&index);

	return list_root;
}
tree *make_linktree(list_tree *root,int count) //根据顺序树 创建 链式结构的树
{
	if (root == NULL)
		return NULL;
	tree *link_root = (tree *)malloc(sizeof(tree));

	int list_index = 0;
	
	link_root->data = root->data;
	link_root->brother = NULL;//根节点没有 右子树
	link_root->firstchild = NULL;
	make_link(root, link_root,count);

	return link_root;
	
}
void make_link(list_tree *root, tree*link_root,int count)
{
	list_tree *child = root;
	tree *temp = NULL;
	int index = find_index(root, link_root->data);
	for (int i=0; i<count; i++,child++)
	{
		if (child->parent == index )
		{
			temp=insert_child(link_root, child->data);
			make_link(root, temp,count);
		}
	}

}
int find_index(list_tree *root, elemtype data)
{
	for (int i = 0; root != NULL; root++, i++)
	{
		if (root->data == data)
		{
			return i;
		}
	}
	return -1;
}
void print_first_tree(tree *root, sq_queue *q) //先根遍历
{
	root = root->firstchild;
	if (root == NULL)
	{
		return;
	}
	in_squeue(q,root);
	while (root->brother != NULL)
	{
		root = root->brother;
		in_squeue(q, root);
	} 
}
void first_order_ltree(tree *root)
{
	if (root == NULL)
		return;
	sq_queue q;
	init_squeue(&q);
	in_squeue(&q, root);
	while (lenth_squeue)
	{
		tree *temp=out_squeue(&q);
		printf("%c ", temp->data);
		print_first_tree(temp, &q);
	}
	
}

void print_last_tree(tree *root)//后根遍历
{

}
void save_file(tree *ptr)
{  //把一个链式的树存在文件中
	int size = 0;
	size_tree(ptr, &size);  //先获得结点个数；
	list_tree *list_root = make_listtree(ptr, size);//得到数组结构的树

	FILE *in = fopen("D:\\My Program\\1008tree\\tree.txt", "w");
	if (in == NULL)
	{
		printf("open file error!!\n");
		return;
	}
	for (int i = 0; i < size; ++i)
	{
		fprintf(in, "%c  , %d", list_root[i].data, list_root[i].parent);
		fputc(10, in);
	}
	fclose(in);
}