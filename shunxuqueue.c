/*
 * shunxuqueue.c
 *
 *  Created on: 2021��5��26��
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>

int length_queue=1;

typedef struct Node{
	int data;
	struct Node *next;
}node;

//˳�����
typedef struct shunxuQueue{
	node *front;//ͷָ��
	node *rear;//βָ��
}sxqueue;

//��ʼ���ڵ�
node *InitialNode(){
	node *n=(node *)malloc(sizeof(node));
	if(n==NULL){
		printf("�ڵ��ڴ����ʧ��\n");
		exit(0);
	}
	return n;
}

//��ʼ������
sxqueue *InitialSXQueue(){
	sxqueue *q=(sxqueue *)malloc(sizeof(sxqueue));
	if(q==NULL){
		printf("�����ڴ����ʧ��\n");
		exit (0);
	}
	////ͷβ������ֵNULL
	q->front=NULL;
	q->rear=NULL;
	return q;
}

//�ж϶����Ƿ�Ϊ�գ��ж϶���ͷָ���Ƿ��ǿ�ֵ
int IsQueueEmpty(sxqueue *p){
	return p->front==NULL;
}

//��Ӳ���
sxqueue *Push_SXqueue(sxqueue *p,int num){
	node *n=InitialNode();
	n->data=num;
	n->next=NULL;
	if(IsQueueEmpty(p)){
		p->front=n;
		p->rear=n;
		printf("����Ϊ�գ���%d���ڵ�%d���\n",length_queue++,num);
		return p;
	}
	else{
		p->rear->next=n;
		p->rear=n;
		printf("��%d���ڵ�%d���\n",length_queue++,num);
		return p;
	}
}

//����
sxqueue *Pop_SXqueue(sxqueue *p){
	//�ж϶����Ƿ�Ϊ��
	if(IsQueueEmpty(p)){
		printf("����Ϊ��\n");
		return p;
	}
	//�ж϶����Ƿ�ֻ��һ��Ԫ��
	if(p->front==p->rear){
		node *temp=p->rear;
		int last_data=temp->data;
		p->front=NULL;
		p->rear=NULL;
		free(temp);
		printf("���һ��Ԫ��%d�ѳ��ӣ����п���\n",last_data);
		return p;
	}
	//��������������ĳ��Ӳ���
	node *temp;
	temp=p->front;
	p->front=temp->next;
	printf("%d����\n",temp->data);
	free(temp);
	return p;
}

//��ӡ����
void Display_SXQueue(sxqueue *p){
	if(IsQueueEmpty(p)){
		printf("����Ϊ��\n");
	}
	node *temp;
	temp=p->front;
	printf("����Ԫ���У� ");
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

