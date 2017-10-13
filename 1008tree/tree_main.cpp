#include <stdio.h>
#include "tree.h"
tree *init_tree();
void find(tree *root);
list_tree* make_list_tree(tree *root);
int main()
{
	tree *root = init_tree();  //初始化链式数  测试成功！
	list_tree *list_root=make_list_tree(root);   //将链式的结构转换成 数组形式的结构  测试成功
	int size = 0;
	size_tree(root, &size); 
	tree *new_root = make_linktree(list_root,size);  //将数组结构的树转换成链式结构的树，测试成功

	find(new_root);  //查询结点  或者查询父节点   测试成功
	//save_file(root);//把一个链式的树存在文件中 测试成功
	/*
	//给链式结构插入一个结点   转换成数组结构，  测试成功
	insert_child(root, 'Z');
	make_list_tree(root);
	*/
	printf("树的先根遍历：");
	first_order_ltree(root);  //先根遍历
	
}
tree *init_tree()
{
	tree *root = make_root('A');
	tree *bp = insert_child(root, 'B');
	tree *cp = insert_child(root, 'C');
	tree *dp = insert_child(root, 'D');
	insert_child(bp, 'E');
	insert_child(bp, 'F');
	tree *gp = insert_child(cp, 'G');
	insert_child(dp, 'H');
	insert_child(dp, 'I');
	tree *jp = insert_child(dp, 'J');
	insert_child(gp, 'K');
	insert_child(gp, 'L');
	insert_child(jp, 'M');
	return root;
}
void find(tree *root)
{
	int size = 0;
	//printf("point count=%d\n", size_tree(root,&size));
	size_tree(root, &size);  //先获得结点个数；
	char ar[] = "ABCDEFGHIJKLM";
	tree *res1 = NULL;
	tree *res2 = NULL;
	for (int i = 0; i < size; i++)
	{
		res1 = find_value(root, ar[i]);
		if (res1 == NULL)
		{
			printf("has not this value :%c!\n",ar[i]);
			continue;
		}
		//printf("find %c  ==  %c\n", ar[i], res1->data);  //测试成功
		res2 = find_parent(root, res1);   //测试成功
		if (res2 == NULL)
		{
			printf("%c has not parent!\n", res1->data);
		}
		else
			printf("%c 'parent is %c\n", res1->data, res2->data);
	}
}
list_tree*  make_list_tree(tree *root)
{
	
	int size = 0;
	//printf("point count=%d\n", size_tree(root,&size));
	size_tree(root, &size);  //先获得结点个数；
	//printf("%d\n", size);
	list_tree *list_root=make_listtree(root, size);
	list_tree*temp = list_root;
	printf("数组结构的树:\n数组下标--结点元素--其父结点的下标\n");
	for (int i = 0; i < size; i++)
	{
		printf("    %d\t--   %c    --   %d\t\n", i, list_root->data,list_root->parent);
		list_root++;
	}
	printf("\n");
	return temp;
}
