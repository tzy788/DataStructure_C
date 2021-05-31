/*
 * binaryTree.c
 *
 *  Created on: 2021��5��27��
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>

//�ڵ�
typedef struct Node{
	int data;
	struct Node *left;
	struct Node *right;
}node;

//���ڵ�
typedef struct Tree{
	 node *root;
}tree;

//��ʼ��һ�ÿ���
tree *InitialBanaryTree(){
	tree *p=(tree *)malloc(sizeof(tree));
	p->root=NULL;
	return p;
}

//�����½ڵ㣬��һ�����������ڵ㣬С�ķ���ߣ���ķ��ұ�
void InsertNodeToTree(tree *p,int num){
	node *newnode=(node *)malloc(sizeof(node));
	newnode->data=num;
	newnode->left=NULL;
	newnode->right=NULL;
	//�ж������Ƿ�Ϊ��
	if(p->root==NULL){//����Ϊ��
		p->root=newnode;
	}
	else{//������Ϊ��
		node *temp=p->root;
		while(temp!=NULL){
			if(num<temp->data){//�²�������ȵ�ǰ�ڵ�С�������
				if(temp->left==NULL){//��ǰ�ڵ����ӽڵ�Ϊ��
					temp->left=newnode;
					return;
				}
				else{
					temp=temp->left;//��������
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

//�������:������
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

//�������:�����
void InorderTraverse(node *p){
	if(p!=NULL){
		InorderTraverse(p->left);
		printf("%d ",p->data);
		InorderTraverse(p->right);
	}
	return;
}

//����������Ҹ�
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

