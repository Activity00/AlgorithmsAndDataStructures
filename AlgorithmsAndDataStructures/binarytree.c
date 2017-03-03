/*
*链式二叉树
*
*题目列表:
*1.求二叉树结点数量
*2.求二叉树的深度
*3.前序遍历、中序遍历、后序遍历  ok
*4.分层遍历二叉树
*5.将二叉查找树变为有序双向链表
*6.求二叉树中第k层的结点数量
*7.求二叉树中叶子结点的数量
*8.判断两颗二叉树结构是否相同
*9.判断两个二叉树是不是平衡二叉树
*10.求二叉树的镜像
*11.求二叉树中两个结点最低公共祖先结点
*12.求二叉树中结点的最大距离
*13.由先序、中序序列重构二叉树。
*14.判断二叉树是不是完全二叉树。
*15.清空二叉树
*16.插入结点与删除结点
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
typedef void(*myfun)(int);//函数指针做函数参数

typedef struct BitNode{
	TElemType data;
	struct BiTNode *lchild, *rchild;
}BitNode,*BiTree;

/*二叉树遍历*/
void vist(TElemType e)
{
	printf("%d\n",e);
}
/*创建二叉树*/
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
	BiTree tree=NULL;//初始化二叉树
	createBitTree(&tree);
	printf("pre:\n ");
	preOrderTraverse(tree, vist);
	printf("in:\n ");
	inOrderTraverse(tree,vist);
	printf("post:\n ");
	postOrderTraverse(tree,vist);
	system("pause");
}