#include <stdio.h>
#include "tree.h"
tree *init_tree();
void find(tree *root);
list_tree* make_list_tree(tree *root);
int main()
{
	tree *root = init_tree();  //��ʼ����ʽ��  ���Գɹ���
	list_tree *list_root=make_list_tree(root);   //����ʽ�Ľṹת���� ������ʽ�Ľṹ  ���Գɹ�
	int size = 0;
	size_tree(root, &size); 
	tree *new_root = make_linktree(list_root,size);  //������ṹ����ת������ʽ�ṹ���������Գɹ�

	find(new_root);  //��ѯ���  ���߲�ѯ���ڵ�   ���Գɹ�
	//save_file(root);//��һ����ʽ���������ļ��� ���Գɹ�
	/*
	//����ʽ�ṹ����һ�����   ת��������ṹ��  ���Գɹ�
	insert_child(root, 'Z');
	make_list_tree(root);
	*/
	printf("�����ȸ�������");
	first_order_ltree(root);  //�ȸ�����
	
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
	size_tree(root, &size);  //�Ȼ�ý�������
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
		//printf("find %c  ==  %c\n", ar[i], res1->data);  //���Գɹ�
		res2 = find_parent(root, res1);   //���Գɹ�
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
	size_tree(root, &size);  //�Ȼ�ý�������
	//printf("%d\n", size);
	list_tree *list_root=make_listtree(root, size);
	list_tree*temp = list_root;
	printf("����ṹ����:\n�����±�--���Ԫ��--�丸�����±�\n");
	for (int i = 0; i < size; i++)
	{
		printf("    %d\t--   %c    --   %d\t\n", i, list_root->data,list_root->parent);
		list_root++;
	}
	printf("\n");
	return temp;
}
