/*
 * Sqstack.c
 *
 *  Created on: 2021��5��31��
 *      Author: HP
 */
#include<stdio.h>
#include<stdlib.h>

#define maxsize 12

//topӦС��maxsize;��ջΪ�գ�top=-1
typedef struct SQstack{
	int data[maxsize];
	int top;		//ջ��ָ��
}sqstack;

int initialSQstack(sqstack *p){
	p->top=-1;
	return 1;
}


int SQstackPush(sqstack *p, int num){
	//�ж�ջ��û��
	if(p->top==maxsize-1){
		printf("ջ��\n");
		return 0;
	}
	p->top++;
	p->data[p->top]=num;
	return 1;
}

int SQstackPop(sqstack *p){
	//�ж�ջ�Ƿ�Ϊ��
	if(p->top==-1){
		printf("ջ��\n");
		return 0;
	}
	p->top--;
	return 1;
}

void DisplaySQstack(sqstack p){
	for(int i=p.top;i>-1;i--){
		printf("%d ",p.data[i]);
	}
	printf("\n");
}


int main(void){
	sqstack t;
	int status;
	status=initialSQstack(&t);
	status=SQstackPush(&t,5);
	status=SQstackPush(&t,78);
	status=SQstackPush(&t,30);
	status=SQstackPush(&t,64);
	DisplaySQstack(t);
	status=SQstackPop(&t);
	status=SQstackPop(&t);
	DisplaySQstack(t);
	return 0;
}


