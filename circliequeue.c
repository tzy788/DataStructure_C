/*
 * circliequeue.c
 *
 *  Created on: 2021��5��26��
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>

//��������Ļ������������õĿռ���maxsize-1������һ��Ӧ���Ǳ��������ַ��
#define maxsize 8

typedef struct CirQueue{
	int data[maxsize];
	int rear;
	int front;
}cirqueue;

//��ʼ��ѭ���б�
cirqueue *InitialCirQueue(){
	cirqueue *p=(cirqueue *)malloc(sizeof(cirqueue));
	if(p==NULL){
		printf("ѭ�����з����ڴ�ʧ��\n");
		exit(0);
	}
	p->front=0;
	p->rear=0;
	return p;
}

//��Ӳ���
cirqueue *Push_Cirqueue(cirqueue *p,int num){
	if(((p->rear+1)%maxsize)==p->front){
		printf("��������,���ʧ��\n");
		return p;
	}
	p->data[(p->rear+1)%maxsize]=num;
	printf("%d��ӳɹ�\n",num);
	p->rear=(p->rear+1)%maxsize;
	return p;
}

//���Ӳ���
cirqueue *Pop_Cirqueue(cirqueue *p){
	if(p->front==p->rear){
		printf("����Ϊ��\n");
		return p;
	}
	//int temp=p->data[p->front];
	p->data[p->front]=0;//frontָ���Ԫ������
	//printf("%d���ӳɹ�\n",temp);
	p->front=(p->front+1)%maxsize;//frontָ����һλ
	return p;
}

//����ѭ������
void DisplayCirQueue(cirqueue *p){
	int temp=p->front;
	while(temp!=p->rear){
		temp=(temp+1)%maxsize;
		printf("%d ",p->data[temp]);

	}
	printf("\n");
}

int main(void){
	cirqueue *t=InitialCirQueue();
	for(int i=1;i<7;i++){
		t=Push_Cirqueue(t,i);
	}
	//printf("%d \n",t->data[1]);
	DisplayCirQueue(t);
	t=Push_Cirqueue(t,45);
	t=Push_Cirqueue(t,463);
	DisplayCirQueue(t);
	//t=Pop_Cirqueue(t);
	//t=Pop_Cirqueue(t);
	//DisplayCirQueue(t);
	return 0;
}

