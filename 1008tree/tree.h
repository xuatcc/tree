#include "queue.h"
#ifndef TREE
#define TREE

typedef char elemtype;
//  ��ʽ�洢
typedef struct tree
{
	elemtype data;
	struct tree *firstchild;
	struct tree *brother;
}tree;
//  ˳��洢
typedef struct list_tree
{
	elemtype data;
	int parent;
}list_tree;

tree *make_root(elemtype x);
tree *insert_child(tree *ptr, elemtype x);
tree *insert_brother(tree *ptr, elemtype x);
tree *find_value(tree *ptr, elemtype x);
tree *find_parent(tree *ptr, tree *child);
tree *parent(tree *ptr, tree *child);
int size_tree(tree *ptr, int *count);  //ͳ�����Ľ�����
list_tree *make_listtree(tree *root, int count);  //������ʽ��������  ˳��ṹ����
void make(tree *ptr, list_tree *list_ptr, int list_ptr_index, int *list_index);
void save_file(tree *ptr);  //��һ����ʽ���������ļ���
tree *make_linktree(list_tree *root, int count); //����˳���� ���� ��ʽ�ṹ����
void make_link(list_tree *root, tree*link_root, int count);
int find_index(list_tree *root, elemtype data);  //��ѯһ��Ԫ����˳�����е�index
void first_order_ltree(tree *root);//�ȸ����� 
void print_last_tree(tree *root);//�������

#endif