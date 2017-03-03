/*
*��ʽ������
*
*��Ŀ�б�:
*1.��������������
*2.������������
*3.ǰ�����������������������  ok
*4.�ֲ����������
*5.�������������Ϊ����˫������
*6.��������е�k��Ľ������
*7.���������Ҷ�ӽ�������
*8.�ж����Ŷ������ṹ�Ƿ���ͬ
*9.�ж������������ǲ���ƽ�������
*10.��������ľ���
*11.������������������͹������Ƚ��
*12.��������н���������
*13.���������������ع���������
*14.�ж϶������ǲ�����ȫ��������
*15.��ն�����
*16.��������ɾ�����
*/
#define _CRT_SECURE_NO_WARNINGS
#define OVERFLOW 0
#define OK 1
#define FALSE -1
#include "stdio.h"
#include "stdlib.h"
#include "stdlib.h"

typedef int TElemType;
typedef int Status;
typedef void(*myfun)(int);//����ָ������������

typedef struct BitNode{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BitNode,*BiTree;

/*����������*/
void vist(TElemType e)
{
	printf("%d\n",e);
}
/*����������*/
Status createBitTree(BiTree* tree)
{
	TElemType e;
	TElemType temp;
	
	scanf("%d",&e);
	if (-1 == e)
	{
		(*tree) = NULL;
	}else{
		(*tree) = (BitNode*)malloc(sizeof(BitNode));
		if (*tree == NULL)
		{
			printf("createBitTree error:overflow! ");
			exit(OVERFLOW);
		}
		(*tree)->data = e;
		createBitTree(&((*tree)->lchild));
		createBitTree(&((*tree)->rchild));
	}
}
Status destoryBitTree(BiTree tree)
{

}
Status preOrderTraverse(BiTree tree,myfun f)
{
	if (tree != NULL)
	{
		f(tree->data);
		preOrderTraverse(tree->lchild,f);
		preOrderTraverse(tree->rchild,f);
	}
		
	
}
Status inOrderTraverse(BiTree tree, myfun f)
{
	if (tree != NULL)
	{
		inOrderTraverse(tree->lchild, f);
		f(tree->data);
		inOrderTraverse(tree->rchild, f);
	}
}
Status postOrderTraverse(BiTree tree, myfun f)
{
	if (tree != NULL)
	{
		postOrderTraverse(tree->lchild, f);
		postOrderTraverse(tree->rchild, f);
		f(tree->data);
	}
}
Status levelOrderTraverse(BiTree tree,myfun f)
{
	if (tree != NULL)
	{
		f(tree->data);
		f(tree->lchild);
		levelOrderTraverse(tree,f);
	}
	
}

void main()
{
	BiTree tree=NULL;//��ʼ��������
	createBitTree(&tree);
	printf("pre:\n ");
	preOrderTraverse(tree, vist);
	printf("in:\n ");
	inOrderTraverse(tree,vist);
	printf("post:\n ");
	postOrderTraverse(tree,vist);
	system("pause");
}