/*
 * linkstack.c
 *
 *  Created on: 2021��5��26��
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>
//ջ�Ľ�����
//���������ƣ����ݺ���һ��ָ��
typedef struct Node{
	int data;
	struct Node *next;
}node;


//��������Ľ�㴴��ջ����Ϊָ��ͷ����topָ��ͼ����õ�count
typedef struct LinkStack{
	node *top;
	int count;
}linkstack;

linkstack *InitialLinkStack(){
	linkstack *p= (linkstack *)malloc(sizeof(linkstack));
	if(p==NULL){
		printf("�޷���ջ�����ڴ�\n");
		exit(0);
	}
	p->top=NULL;
	p->count=0;
	return p;
}

//�����Ͼ��Ǹ�������
linkstack *Push(linkstack *p,int data){
	node *temp=(node *)malloc(sizeof(node));//�½ڵ�
	if(temp==NULL){
		printf("�޷����½ڵ�����ڴ�\n");
		exit(0);
	}
	temp->data=data;
	temp->next=p->top;//�½ڵ��nextָ��ǰһ���ڵ�
	p->top=temp;//ջ��topָ���½ڵ�
	p->count++;
	printf("%d��ջ,ջ����%d��Ԫ��\n",data,p->count);
	return p;
}

linkstack *Pop(linkstack *p){
	if(p->top==NULL){
		printf("ջΪ��\n");
		return p;
	}
	printf("ջ��Ԫ��Ϊ%d,��ջ��",p->top->data);
	node *temp=p->top;
	p->top=p->top->next;
	free(temp);
	p->count--;
	printf("���ڵ�ջ��Ԫ��Ϊ%d\n",p->top->data);
	return p;
}

void DisplayLinkStack(linkstack *p){
	if(p->top==NULL){
		printf("ջΪ��\n");
	}
	node *temp=p->top;
	while(temp!=NULL){
		printf("%d  ",temp->data);
		temp=temp->next;
	}
	printf("\n");

}
//
//int main(void){
//	linkstack *t=InitialLinkStack();
//	t=Push(t,5);
//	t=Push(t,78);
//	t=Push(t,56);
//	t=Push(t,12);
//	DisplayLinkStack(t);
//	t=Pop(t);
//	t=Pop(t);
//	DisplayLinkStack(t);
//	return 0;
//}


