#include "queue.h"
#ifndef TREE
#define TREE

typedef char elemtype;
//  链式存储
typedef struct tree
{
	elemtype data;
	struct tree *firstchild;
	struct tree *brother;
}tree;
//  顺序存储
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
int size_tree(tree *ptr, int *count);  //统计数的结点个数
list_tree *make_listtree(tree *root, int count);  //根据链式的树创建  顺序结构的树
void make(tree *ptr, list_tree *list_ptr, int list_ptr_index, int *list_index);
void save_file(tree *ptr);  //把一个链式的树存在文件中
tree *make_linktree(list_tree *root, int count); //根据顺序树 创建 链式结构的树
void make_link(list_tree *root, tree*link_root, int count);
int find_index(list_tree *root, elemtype data);  //查询一个元素在顺序树中的index
void first_order_ltree(tree *root);//先根遍历 
void print_last_tree(tree *root);//后根遍历

#endif