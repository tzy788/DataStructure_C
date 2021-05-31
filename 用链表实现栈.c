/*
 * linkstack.c
 *
 *  Created on: 2021年5月26日
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>
//栈的结点设计
//单个结点设计，数据和下一个指针
typedef struct Node{
	int data;
	struct Node *next;
}node;


//利用上面的结点创建栈，分为指向头结点的top指针和计数用的count
typedef struct LinkStack{
	node *top;
	int count;
}linkstack;

linkstack *InitialLinkStack(){
	linkstack *p= (linkstack *)malloc(sizeof(linkstack));
	if(p==NULL){
		printf("无法给栈分配内存\n");
		exit(0);
	}
	p->top=NULL;
	p->count=0;
	return p;
}

//本质上就是个单链表
linkstack *Push(linkstack *p,int data){
	node *temp=(node *)malloc(sizeof(node));//新节点
	if(temp==NULL){
		printf("无法给新节点分配内存\n");
		exit(0);
	}
	temp->data=data;
	temp->next=p->top;//新节点的next指向前一个节点
	p->top=temp;//栈顶top指向新节点
	p->count++;
	printf("%d入栈,栈里有%d个元素\n",data,p->count);
	return p;
}

linkstack *Pop(linkstack *p){
	if(p->top==NULL){
		printf("栈为空\n");
		return p;
	}
	printf("栈顶元素为%d,出栈，",p->top->data);
	node *temp=p->top;
	p->top=p->top->next;
	free(temp);
	p->count--;
	printf("现在的栈顶元素为%d\n",p->top->data);
	return p;
}

void DisplayLinkStack(linkstack *p){
	if(p->top==NULL){
		printf("栈为空\n");
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


