/*
 * shunxuqueue.c
 *
 *  Created on: 2021年5月26日
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>

int length_queue=1;

typedef struct Node{
	int data;
	struct Node *next;
}node;

//顺序队列
typedef struct shunxuQueue{
	node *front;//头指针
	node *rear;//尾指针
}sxqueue;

//初始化节点
node *InitialNode(){
	node *n=(node *)malloc(sizeof(node));
	if(n==NULL){
		printf("节点内存分配失败\n");
		exit(0);
	}
	return n;
}

//初始化队列
sxqueue *InitialSXQueue(){
	sxqueue *q=(sxqueue *)malloc(sizeof(sxqueue));
	if(q==NULL){
		printf("队列内存分配失败\n");
		exit (0);
	}
	////头尾结点均赋值NULL
	q->front=NULL;
	q->rear=NULL;
	return q;
}

//判断队列是否为空：判断队列头指针是否是空值
int IsQueueEmpty(sxqueue *p){
	return p->front==NULL;
}

//入队操作
sxqueue *Push_SXqueue(sxqueue *p,int num){
	node *n=InitialNode();
	n->data=num;
	n->next=NULL;
	if(IsQueueEmpty(p)){
		p->front=n;
		p->rear=n;
		printf("队列为空，第%d个节点%d入队\n",length_queue++,num);
		return p;
	}
	else{
		p->rear->next=n;
		p->rear=n;
		printf("第%d个节点%d入队\n",length_queue++,num);
		return p;
	}
}

//出队
sxqueue *Pop_SXqueue(sxqueue *p){
	//判断队列是否为空
	if(IsQueueEmpty(p)){
		printf("队列为空\n");
		return p;
	}
	//判断队列是否只有一个元素
	if(p->front==p->rear){
		node *temp=p->rear;
		int last_data=temp->data;
		p->front=NULL;
		p->rear=NULL;
		free(temp);
		printf("最后一个元素%d已出队，队列空了\n",last_data);
		return p;
	}
	//除以上两种情况的出队操作
	node *temp;
	temp=p->front;
	p->front=temp->next;
	printf("%d出队\n",temp->data);
	free(temp);
	return p;
}

//打印队列
void Display_SXQueue(sxqueue *p){
	if(IsQueueEmpty(p)){
		printf("队列为空\n");
	}
	node *temp;
	temp=p->front;
	printf("队列元素有： ");
	while(temp){
		printf("%d ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}

//int main(void){
//	sxqueue *t=InitialSXQueue();
//	t=Push_SXqueue(t,8);
//	t=Push_SXqueue(t,46);
//	Display_SXQueue(t);
//	t=Pop_SXqueue(t);
//	t=Pop_SXqueue(t);
//
//
//
//	return 0;
//}

