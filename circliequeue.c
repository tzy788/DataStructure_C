/*
 * circliequeue.c
 *
 *  Created on: 2021年5月26日
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>

//利用数组的话，数组内能用的空间是maxsize-1，其中一个应该是被用来存地址。
#define maxsize 8

typedef struct CirQueue{
	int data[maxsize];
	int rear;
	int front;
}cirqueue;

//初始化循环列表
cirqueue *InitialCirQueue(){
	cirqueue *p=(cirqueue *)malloc(sizeof(cirqueue));
	if(p==NULL){
		printf("循环队列分配内存失败\n");
		exit(0);
	}
	p->front=0;
	p->rear=0;
	return p;
}

//入队操作
cirqueue *Push_Cirqueue(cirqueue *p,int num){
	if(((p->rear+1)%maxsize)==p->front){
		printf("队列已满,入队失败\n");
		return p;
	}
	p->data[(p->rear+1)%maxsize]=num;
	printf("%d入队成功\n",num);
	p->rear=(p->rear+1)%maxsize;
	return p;
}

//出队操作
cirqueue *Pop_Cirqueue(cirqueue *p){
	if(p->front==p->rear){
		printf("队列为空\n");
		return p;
	}
	//int temp=p->data[p->front];
	p->data[p->front]=0;//front指向的元素清零
	//printf("%d出队成功\n",temp);
	p->front=(p->front+1)%maxsize;//front指向下一位
	return p;
}

//遍历循环队列
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

