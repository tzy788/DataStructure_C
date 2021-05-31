/*
 * binaryTree.c
 *
 *  Created on: 2021年5月27日
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>

//节点
typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}node;

//根节点
typedef struct Tree{
	 node *root;
}tree;

//初始化一棵空树
tree *InitialBanaryTree(){
	tree *p=(tree *)malloc(sizeof(tree));
	p->root=NULL;
	return p;
}

//插入新节点，第一个数赋给根节点，小的放左边，大的放右边
void InsertNodeToTree(tree *p,int num){
	node *newnode=(node *)malloc(sizeof(node));
	newnode->data=num;
	newnode->left=NULL;
	newnode->right=NULL;
	//判断树根是否为空
	if(p->root==NULL){//树根为空
		p->root=newnode;
	}
	else{//树根不为空
		node *temp=p->root;
		while(temp!=NULL){
			if(num<temp->data){//新插入的数比当前节点小，放左边
				if(temp->left==NULL){//当前节点左子节点为空
					temp->left=newnode;
					return;
				}
				else{
					temp=temp->left;//继续往下
				}

			}
			else{
				if(temp->right==NULL){
					temp->right=newnode;
					return;
				}
				else{
					temp=temp->right;
				}

			}

		}
	}

}

//先序遍历:根左右
void PreorderTraverse(node *p){
	if(p!=NULL){
		printf("%d ",p->data);
		if(p->left!=NULL)
			PreorderTraverse(p->left);
		if(p->right!=NULL)
			PreorderTraverse(p->right);
	}
	return;

}

//中序遍历:左根右
void InorderTraverse(node *p){
	if(p!=NULL){
		InorderTraverse(p->left);
		printf("%d ",p->data);
		InorderTraverse(p->right);
	}
	return;
}

//后序遍历左右根
void PostorderTraverse(node* p){
	if(p!=NULL){
		PostorderTraverse(p->left);
		PostorderTraverse(p->right);
		printf("%d ",p->data);
	}
	return;

}

int main(void){
	tree *t=InitialBanaryTree();
	InsertNodeToTree(t,5);
	InsertNodeToTree(t,8);
	InsertNodeToTree(t,1);
	InsertNodeToTree(t,6);
	InsertNodeToTree(t,2);
	InsertNodeToTree(t,3);
	PreorderTraverse(t->root);
	printf("\n");
	InorderTraverse(t->root);
	printf("\n");
	PostorderTraverse(t->root);
	return 0;
}

